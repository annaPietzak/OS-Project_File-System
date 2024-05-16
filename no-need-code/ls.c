#include <stdio.h>
#include <dirent.h>
#include <sys/xattr.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // For rename()

#define MAX_PATH_LENGTH 1024
#define MAX_ATTR_SIZE 1024

void change_files(const char *dir_path, const char *tagName) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            change_files(full_path, tagName);

            // Check directory attribute
            char value[MAX_ATTR_SIZE];
            ssize_t attr_size = getxattr(full_path, tagName, value, sizeof(value));
            if (attr_size < 0) {
                // Attribute not found, rename the directory
                char new_name[MAX_PATH_LENGTH];
                snprintf(new_name, sizeof(new_name), "%s/.%s", dir_path, entry->d_name);
                if (rename(full_path, new_name) != 0) {
                    perror("rename");
                }
            }
        } else if (entry->d_type == DT_REG) {
            char value[MAX_ATTR_SIZE];
            ssize_t attr_size = getxattr(full_path, tagName, value, sizeof(value));
            if (attr_size < 0) {
                // Attribute not found, rename the file
                char new_name[MAX_PATH_LENGTH];
                snprintf(new_name, sizeof(new_name), "%s/.%s", dir_path, entry->d_name);
                if (rename(full_path, new_name) != 0) {
                    perror("rename");
                }
            } else {
                // Attribute found, print filename
                printf("%s\n", full_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <path> user.<tagname>\n", argv[0]);
        return 1;
    }

    const char *start_dir = argv[1];
    const char *attr_name = argv[2];

    printf("These are all the files with the tag %s\n", attr_name);
    change_files(start_dir, attr_name);

    return 0;
}
