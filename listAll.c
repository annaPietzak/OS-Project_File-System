#include <sys/xattr.h>
#include <stdio.h>
#include <string.h>

#define MAX_ATTR_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char attr_list[MAX_ATTR_SIZE];
    ssize_t attr_size;

    // List all the extended attribute names
    attr_size = listxattr(argv[1], attr_list, sizeof(attr_list));
    if (attr_size == -1) {
        perror("listxattr");
        return 1;
    }

    // Print all the extended attribute names
    printf("Extended attributes for %s:\n", argv[1]);
    char *attr_name = attr_list;
    while (attr_name < attr_list + attr_size) {
        printf("%s\n", attr_name);
        attr_name += strlen(attr_name) + 1; // Move to the next attribute name
    }

    return 0;
}
