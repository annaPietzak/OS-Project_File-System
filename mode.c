#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/xattr.h>

#define MAX_PATH_LENGTH 1024
#define MAX_ATTR_SIZE 1024

int has_tagged_file(const char *file_path, const char *tagName) {
    char value[MAX_ATTR_SIZE];
    ssize_t attr_size = getxattr(file_path, tagName, value, sizeof(value));

    if (attr_size >= 0) { // Check if attribute or no attribute
        return 1; // Indicates the file has the attribute
    }

    return 0; // No attribute found
}

int search_files(const char *dir_path, const char *tagName) {
    DIR *dir = opendir(dir_path);

    if (!dir) {
        perror("Error opening directory (search_files)");
        return 0; // Return 0 on failure
    }

    struct dirent *entry;
    int has_tagged = 0; // Flag to indicate if any file with the attribute was found
    char full_path[MAX_PATH_LENGTH];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip dot directories
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) { // Only recurse if it's a directory
            printf("Checking directory (search_files): %s\n", full_path); // Debug print

            int subdir_has_tagged = search_files(full_path, tagName); // Recursive call
            if (subdir_has_tagged) {
                has_tagged = 1; // Prevent renaming if tagged file exists in subdirectories
            }
        } else if (entry->d_type == DT_REG) { // If it's a regular file
            printf("It's a normal file (search_files): %s\n", full_path); // Debug print
            if (has_tagged_file(full_path, tagName)) { // Check for tag
                has_tagged = 1; // Prevent renaming if tagged file found
            }
        }
    }

    closedir(dir); // Close the directory before further operations

    if (!has_tagged) { // No tagged file found, safe to rename
        // Derive the last component of the directory path for renaming
        printf("Directory Path: %s\n", full_path);
        char *last_part = strrchr(full_path, '/'); // Get the last component of the path
        if (last_part) {
            last_part++; // Move past the '/' to get the actual name
            printf("File name: %s\n", last_part); // This should print the file name
        } else {
            last_part = (char *)full_path; // If no '/', use the entire path
        }

        char new_name[MAX_PATH_LENGTH];
        snprintf(new_name, sizeof(new_name), "%s/.%s", dir_path, last_part); // Construct the new name

        if (rename(full_path, new_name) != 0) { // Rename the directory
            perror("Error renaming directory (search_files)");
        } else {
            printf("Directory '%s' renamed to '%s' (search_files)\n", full_path, new_name);
        }
    }

    return has_tagged; // Return flag indicating whether a tagged file was found
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <attribute name> <starting path>\n", argv[0]);
        return 1;
    }

    const char *attr = argv[1];
    const char *start_dir = argv[2];

    printf("Starting search in directory '%s' with tag '%s'\n", start_dir, attr);

    search_files(start_dir, attr);

    return 0;
}
