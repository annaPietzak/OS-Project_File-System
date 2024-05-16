#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAX_ATTR_NAME_SIZE 255

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <tag_name> <file_path>\n", argv[0]);
        return 1;
    }

    char *tagName = argv[1];
    char *filePath = argv[2];

    // Concatenate user.tagName to get user.<tag_name>
    char attr_name[MAX_ATTR_NAME_SIZE];
    snprintf(attr_name, MAX_ATTR_NAME_SIZE, "user.%s", tagName);

    // Remove the specified extended attribute
    if (removexattr(filePath, attr_name) == -1) {
        fprintf(stderr, "Failed to remove attribute '%s' from file '%s': %s\n", attr_name, filePath,
                strerror(errno));
        return 1;
    }

    // Print when it was successful
    printf("Tag %s removed successfully from file %s\n", attr_name, filePath);

    return 0;
}
