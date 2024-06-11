#include "include/checkFilePath.h"

/**
 * This method checks, if the file_path exists and if it's a file or a directory. The check
 * succeeds if the path points to a non existing file or if it's not a directory
 * @param filePath the path to the file, where the user wants to either create a file and add
 * a tag or just add a tag
 * @return 0 or 1 depending on if it worked or not
 */

int check_file_path(const char * filePath) {
    if (access(filePath, F_OK) == 0) {
        // file exists, need to check if it is directory

        struct stat statbuf;
        if (stat(filePath, &statbuf) != 0)
            // statbuf couldn't be created
            return 1;
        if (S_ISDIR(statbuf.st_mode)) {
            // file is a directory
            return 1;
        }
        return 0;
    } else {
        // file does not exist, so we can create it
        return 0;
    }


}
