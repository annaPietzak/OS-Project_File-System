#include <fcntl.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file_path> user.<tagname> <tagvalue>\n", argv[0]);
        return 1;
    }

    int fd2 = open(argv[1], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);

    // Set the extended attribute on the file
    if (setxattr(argv[1], argv[2], argv[3], strlen(argv[3]), 0) == -1) {
        perror("setxattr");
        return 1;
    }

    printf("Tag %s set successfully for file %s with name %s\n", argv[3], argv[1], argv[1]);
}
