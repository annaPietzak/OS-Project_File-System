#include "include/listAll.h"

/**
 * This function shows you the different tags that the file at filePath has.
 * @param filePath the file you want to have all tags listed
 * @return 0 or 1 depending if it worked or not
 */

int list_all_tags(const char * filePath) {
    // Check if the argument is missing
    if (filePath == NULL) {
        fprintf(stderr, "Error: The attribute is missing. "
                        "Please check your input\n");
        return 1;
    }

    ssize_t attr_size;

    // Get the size of the extended attributes list
    attr_size = listxattr(filePath, NULL, 0);
    if (attr_size == -1) {
        fprintf(stderr, "Something went wrong when accessing the file: %s\n", strerror(errno));
        return 1;
    }

    // Allocate memory for the attribute list
    char *attr_list = malloc(attr_size);
    if (!attr_list) {
        fprintf(stderr, "Error: Couldn't allocate memory (malloc)");
        return 1;
    }

    // Get the actual list of extended attributes
    attr_size = listxattr(filePath, attr_list, attr_size);
    if (attr_size == -1) {
        fprintf(stderr, "Something went wrong when accessing the file: %s\n", strerror(errno));
        free(attr_list);
        return 1;
    } else if (attr_size == 0) {
        // If there aren't any tags, return this
        printf("File %s doesn't have any tags attached\n", filePath);
        free(attr_list);
        return 0;
    }

    // Print all the extended attribute names
    printf("Extended attributes for %s:\n", filePath);
    char *attr_name = attr_list;
    while (attr_name < attr_list + attr_size) {
        char attr_value[MAX_ATTR_VALUE_SIZE];
        ssize_t value_size = getxattr(filePath, attr_name, attr_value, sizeof(attr_value));
        if (value_size == -1) {
            fprintf(stderr, "Error: Couldn't get value for attribute '%s' because %s",
                    attr_name, strerror(errno));
            // Move to the next attribute name
            attr_name += strlen(attr_name) + 1;
            continue;
        }
        // Null-terminate the attribute value string
        attr_value[value_size] = '\0';
        printf("%s = \"%s\"\n", attr_name, attr_value);
        // Move to the next attribute name
        attr_name += strlen(attr_name) + 1;
    }

    // Clean up
    free(attr_list);
    return 0;
}
