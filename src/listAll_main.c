#include "include/listAll.h"

/**
 * This is the main function to listAll.c. It calls the function in listAll.c.
 * @param argc argument count
 * @param argv argument filePath
 * @return 0 or 1 depending on if it worked or not
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    char *filePath = argv[1];

    // Lists all tags that that file has
    list_all_tags(filePath);

    return 0;
}
