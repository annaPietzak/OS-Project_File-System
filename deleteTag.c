#include <sys/xattr.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_path> user.<tagname>\n", argv[0]);
        return 1;
    }

    if (removexattr(argv[1], argv[2]) == -1) {
        perror("removexattr");
        return 1;
    }

    printf("Tag %s removed successfully from file %s\n", argv[2], argv[1]);

    return 0;
}
