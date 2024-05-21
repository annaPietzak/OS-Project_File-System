#include "include/deleteTag.h"

int delete_tag_from_file(const char * tagName, const char * filePath) {
    // Concatenate user.tagName to get user.<tag_name>
    char attr_name[MAX_ATTR_NAME_SIZE];
    snprintf(attr_name, MAX_ATTR_NAME_SIZE, "user.%s", tagName);

    // Remove the specified extended attribute
    if (removexattr(filePath, attr_name) == -1) {
        fprintf(stderr, "Failed to remove attribute '%s' from file '%s': %s\n", attr_name, filePath,
                strerror(errno));
        return 1;
    }

    return 0;
}
