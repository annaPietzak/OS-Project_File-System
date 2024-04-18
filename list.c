#include <sys/xattr.h>
#include <stdio.h>

#define MAX_ATTR_SIZE 1024

int main (int argc, char * argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_path> <tagname>\n", argv[0]);
        return 1;
    }

    char attr_value[MAX_ATTR_SIZE];

    // Concatenate user.argv[2] to get user.<tagname>
    char attr_name[MAX_ATTR_SIZE];
    sprintf(attr_name, "user.%s",argv[2]);

    // Get the extended attribute and give it a size
    ssize_t attr_size = getxattr(argv[1], attr_name, attr_value, sizeof(attr_value));
    if (attr_size == -1) {
        perror("getxattr");
        return 1;
    }

    // Null terminate the extended attribute value
    attr_value[attr_size] = '\0';

    // Print the value of the extended attribute
    printf("Tag with attribute name %s has value %s\n", attr_name, attr_value);
}
