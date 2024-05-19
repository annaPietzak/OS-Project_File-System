#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "include/isValidString.h"
#include "include/checkLengthName.h"

#define MAX_ATTR_NAME_SIZE 255

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <tag_name> <file_path>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *filePath = argv[2];

    // Check if combined length of "user." and tagName is longer than allowed
    if (check_tag_name(tagName) == 1) {
        fprintf(stderr, "Error: The total length of 'user.%s' exceeds the limit of %d characters\n",
                tagName, MAX_ATTR_NAME_SIZE - 1);
        return 1;
    }

    // Check if the tagName contains any non-alphanumeric characters
    if (is_valid_string(tagName) == 1) {
        fprintf(stderr, "Error: Tag name '%s' contains invalid characters. "
                        "Only alphanumeric and underscores are allowed.\n", tagName);
        return 1;
    }

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
