#include <fcntl.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_ATTR_SIZE 1024

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: %s <tag_name> <tag_value> <file_path>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *tagValue = argv[2];
    char *filePath = argv[3];

    // Create file with rwx permissions for user, group, other
    int file = open(filePath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (file == -1) {
        perror("open");
        return 1;
    }

    // Concatenate user.tagName to get user.<tag_name>
    char attr_name[MAX_ATTR_SIZE];
    snprintf(attr_name, sizeof(attr_name), "user.%s", tagName);

    // Set the extended attribute on the file
    if (setxattr(filePath, attr_name, tagValue, strlen(tagValue), 0) == -1) {
        perror("setxattr");
        close(file);
        return 1;
    }

    // Print statement of extended attribute
    printf("Tag %s set successfully for file %s with name %s\n", tagValue, filePath, attr_name);

    close(file);
    return 0;
}
