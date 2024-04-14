#include <sys/xattr.h>
#include <stdio.h>

#define MAX_ATTR_SIZE 1024

int main (int argc, char * argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_path> user.<tagname>\n", argv[0]);
        return 1;
    }

    char attr_value[MAX_ATTR_SIZE];
    ssize_t attr_size;

    // List the extended attribute
    attr_size = getxattr(argv[1], argv[2], attr_value, sizeof(attr_value));
    if (attr_size == -1) {
        perror("getxattr");
        return 1;
    }

    // Print the value of the extended attribute
    printf("Tag with attribute name %s has value %s\n", argv[2], attr_value);
}
