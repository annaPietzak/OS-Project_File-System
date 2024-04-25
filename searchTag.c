#include <stdio.h>
#include <dirent.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 1024
#define MAX_ATTR_SIZE 1024

void search_files(const char *dir_path, const char *tagName) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    // Loop through each entry of the directory
    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        // Concatenate dir_path (current directory path) with entry->d_name (name of the file) and
        // snprintf for full path fits into 'full_path' buffer without overflowing
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Check if it's a directory
        if (entry->d_type == DT_DIR) {
            // Skip "." and ".." files
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Continue search directories
            search_files(full_path, tagName);
        } else if (entry->d_type == DT_REG) {
            // Regular file
            char tagValue[MAX_ATTR_SIZE];
            ssize_t size = getxattr(full_path, tagName, tagValue, sizeof(tagValue));
            if (size > 0) {
                printf("File '%s' has tag '%s': %s\n", full_path, tagName, tagValue);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char * argv[]) {
    const char *start_dir = argv[1];
    const char *attr = argv[2];

    if (argc < 3) {
        printf("Usage: %s <file_path> user.<tagname>\n", argv[0]);
        return 1;
    }

    printf("Searching for files with tag '%s' in directory '%s'\n", attr, start_dir);
    search_files(start_dir, attr);

    return 0;
}

