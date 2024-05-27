#include "include/mkfile.h"

/**
 * This function creates a file at filePath with the specified tagName and tagValue.
 * If the file doesn't exist, then it creates a new one. Otherwise it just adds the tag to the
 * existing file
 * @param tagName the name the tag should have
 * @param tagValue the value the tag should have
 * @param filePath where the file is located
 * @return 1 or 0 depending on if it worked or not
 */

int create_file_with_attribute(const char *tagName, const char *tagValue, const char *filePath) {
    // Check if one of the three arguments is missing
    if (tagName == NULL || tagValue == NULL || filePath == NULL) {
        fprintf(stderr, "Error: One of the three attributes is missing. "
                        "Please check that all of them are there\n");
        return 1;
    }

    // Concatenate user. and tagName to get user.<tag_name>
    char attr_name[MAX_ATTR_NAME_SIZE];
    snprintf(attr_name, sizeof(attr_name), "user.%s", tagName);

    // Create file with rwx permissions for user, group, other
    int file = open(filePath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (file == -1) {
        perror("open");
        return 1;
    }

    // Set the attribute on the file
    size_t valueLength = strlen(tagValue);
    if (setxattr(filePath, attr_name, tagValue, valueLength, 0) == -1) {
        perror("setxattr");
        close(file);
        return 1;
    }

    close(file);
    return 0;
}
