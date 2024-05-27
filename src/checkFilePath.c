#include "include/checkFilePath.h"

// Check if path points to file and not directory
int check_file_path(const char * filePath) {
    struct stat statbuf;
    if (stat(filePath, &statbuf) != 0)
        return 1;
    if (S_ISDIR(statbuf.st_mode)) {
        return 1;
    }
    return 0;
}
