#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ATTR_VALUE_SIZE 3073

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *filePath = argv[1];
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
    }

    // Print all the extended attribute names
    printf("Extended attributes for %s:\n", argv[1]);
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