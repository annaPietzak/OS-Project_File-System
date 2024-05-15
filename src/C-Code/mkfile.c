#include <fcntl.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_ATTR_NAME_SIZE 255
#define MAX_ATTR_VALUE_SIZE 3073

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: %s <tag_name> <tag_value> <file_path>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *tagValue = argv[2];
    char *filePath = argv[3];

    // Check the combined length of "user." and tagName
    size_t fullTagNameLength = strlen("user.") + strlen(tagName);
    printf("Full attribute name length: %zu\n", fullTagNameLength);

    if (fullTagNameLength >= MAX_ATTR_NAME_SIZE) {
        fprintf(stderr, "Error: The total length of 'user.%s' exceeds the limit of %d characters\n",
                tagName, MAX_ATTR_NAME_SIZE - 1);
        return 1;
    }

    // Concatenate user. and attr_name to get user.<tag_name>
    char attr_name[MAX_ATTR_NAME_SIZE];
    snprintf(attr_name, sizeof(attr_name), "user.%s", tagName);
    printf("attr_name: %s\n", attr_name);

    // Create file with rwx permissions for user, group, other
    int file = open(filePath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (file == -1) {
        perror("open");
        return 1;
    }

    // Check if the attribute value exceeds the maximum allowed length
    size_t valueLength = strlen(tagValue);
    printf("valueLength: %zu\n", valueLength);
    if (valueLength > MAX_ATTR_VALUE_SIZE) {
        fprintf(stderr, "Error: The tag value exceeds the maximum allowed length of %d characters\n",
                MAX_ATTR_VALUE_SIZE - 1);
        close(file);
        return 1;
    }

    // Set the attribute on the file
    if (setxattr(filePath, attr_name, tagValue, fullTagNameLength, 0) == -1) {
        perror("setxattr");
        close(file);
        return 1;
    }

    // Print when it was successful
    printf("Tag %s set successfully for file %s with name %s\n", tagValue, filePath, attr_name);

    close(file);
    return 0;
}
