#include <fcntl.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdio.h>

#define MAX_ATTR_SIZE 1024

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file_path> <tagname> <tagvalue>\n", argv[0]);
        return 1;
    }

    // Create file with rwx permissions for user, group, other
    int file = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (file == -1) {
        perror("open");
        return 1;
    }

    // Concatenate user.argv[2] to get user.<tagname>
    char attr_name[MAX_ATTR_SIZE];
    sprintf(attr_name, "user.%s",argv[2]);

    // Set the extended attribute on the file
    if (setxattr(argv[1], attr_name, argv[3], strlen(argv[3]), 0) == -1) {
        perror("setxattr");
        return 1;
    }

    // Print statement of extended attribute
    printf("Tag %s set successfully for file %s with name %s\n", argv[3], argv[1], attr_name);
}
