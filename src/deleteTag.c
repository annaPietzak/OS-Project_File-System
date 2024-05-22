#include "include/deleteTag.h"

int delete_tag_from_file(const char * tagName, const char * filePath) {
    // Check if one of the two arguments is missing
    if (tagName == NULL || filePath == NULL) {
        fprintf(stderr, "Error: One of the two attributes is missing. "
                        "Please check that all of them are there\n");
        return 1;
    }

    // Concatenate user.tagName to get user.<tag_name>
    char attr_name[MAX_ATTR_NAME_SIZE];
    snprintf(attr_name, MAX_ATTR_NAME_SIZE, "user.%s", tagName);

    // Check if the tag exists
    char dummy_value;
    ssize_t result = getxattr(filePath, attr_name, &dummy_value, sizeof(dummy_value));
    if (result == -1 && errno == ENODATA) {
        fprintf(stderr, "This tag doesn't exist on %s. Please choose another one to delete\n", filePath);
        return 1;
    }

    // Remove the specified extended attribute
    if (removexattr(filePath, attr_name) == -1) {
        fprintf(stderr, "Failed to remove attribute '%s' from file '%s': %s\n", attr_name, filePath,
                strerror(errno));
        return 1;
    }

    return 0;
}
