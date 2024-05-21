#include "include/listAll.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *filePath = argv[1];
    list_all_tags(filePath);

    return 0;
}
