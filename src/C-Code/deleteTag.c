#include <sys/xattr.h>
#include <stdio.h>

#define MAX_ATTR_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_path> <tagname>\n", argv[0]);
        return 1;
    }

    // Concatenate user.argv[2] to get user.<tagname>
    char attr_name[MAX_ATTR_SIZE];
    sprintf(attr_name, "user.%s",argv[2]);

    // Remove the specified extended attribute
    if (removexattr(argv[1], attr_name) == -1) {
        perror("removexattr");
        return 1;
    }

    // Print when it was successful
    printf("Tag %s removed successfully from file %s\n", attr_name, argv[1]);

    return 0;
}
