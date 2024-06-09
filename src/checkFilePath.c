#include "include/checkFilePath.h"

// Check if path exists and if it is a file or directory
// the check succeeds if the path does not point to a file, or if the file is not a directory
int check_file_path(const char * filePath) {
    if (access(argv[1], F_OK) == 0) {
        //file exists, need to check if it is directory

        struct stat statbuf;
        if (stat(filePath, &statbuf) != 0)
            return 1;
        if (S_ISDIR(statbuf.st_mode)) {
            return 1;
        }
        return 0;
    } else {
        //file does not exist, so we can create it
        return 0;
    }


}
