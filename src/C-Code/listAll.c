#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        fprintf(stderr, "Error when getting size of extended attributes list (listxattr 1)");
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
        fprintf(stderr, "Error: Couldn't get actual list of attributes (listxattr 2)");
        free(attr_list);
        return 1;
    }

    // Print all the extended attribute names
    printf("Extended attributes for %s:\n", argv[1]);
    char *attr_name = attr_list;
    while (attr_name < attr_list + attr_size) {
        printf("%s\n", attr_name);
        attr_name += strlen(attr_name) + 1; // Move to the next attribute name
    }

    // Clean up
    free(attr_list);

    return 0;
}
