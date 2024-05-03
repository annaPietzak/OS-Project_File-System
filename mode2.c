#include <stdio.h>
#include <stdlib.h>
#include <fts.h>
#include <string.h>
#include <sys/xattr.h>
#include <errno.h>

#define MAX_PATH_LENGTH 2000
#define MAX_ATTR_SIZE 2000

int has_tagged_file(const char *file_path, const char *expected_tag) {
    char value[MAX_ATTR_SIZE];

    ssize_t attr_size = getxattr(file_path, expected_tag, value, sizeof(value));

    if (attr_size >= 0) { // Check if attribute or no attribute
        return 1; // Indicates the file has the attribute
    }

    return 0; // No attribute found
}

void process_files(const char *start_dir, const char *expected_tag) {
    char *paths[] = { (char *)start_dir, NULL };
    FTS *fts = fts_open(paths, FTS_NOCHDIR | FTS_COMFOLLOW, NULL);


    if (!fts) {
        perror("Error opening FTS");
        return;
    }

    FTSENT *node;
    int current_dir_has_tagged = 0;
    char last_dir[MAX_PATH_LENGTH] = {0};

    while ((node = fts_read(fts)) != NULL) {
        //printf("FTS Path: %s\n", node->fts_path); // Print each traversed path
        switch (node->fts_info) {
            case FTS_D: // Directory
                if (node->fts_level == 1) { // Top-level directories
                    current_dir_has_tagged = 0; // Reset flag
                    strncpy(last_dir, node->fts_path, MAX_PATH_LENGTH - 1); // Track directory
                    last_dir[MAX_PATH_LENGTH - 1] = '\0';
                    printf("Checking directory: %s\n", node->fts_path); // Debug print
                }
                break;
            case FTS_F: // Regular file
                printf("Checking file: %s\n", node->fts_path);

                if (has_tagged_file(node->fts_path, expected_tag)) {
                    current_dir_has_tagged = 1; // Flag if tagged file found
                    printf("File has tag: %s\n", node->fts_path);
                } else {
                    printf("File doesn't have that tag: %s\n", node->fts_path);
                }
                break;
            default:
                printf("Ignoring non-regular file: %s\n", node->fts_path);
                break;
        }
    }

    fts_close(fts);

    char *base_name = strrchr(last_dir, '/');
    if (base_name == NULL) {
        fprintf(stderr, "Error: Unable to determine base name from path: %s\n", last_dir);
        return;
    }
    base_name++; // Move past the slash

    if (current_dir_has_tagged == 0 && last_dir[0] != '\0') { // Rename if no tagged files
        printf("Renaming has started");
        char new_name[MAX_PATH_LENGTH];

        if (strlen(last_dir) + 3 + strlen(strrchr(last_dir, '/') + 1) >= MAX_PATH_LENGTH) {
            fprintf(stderr, "Warning: Path may be too long, renaming might cause buffer overflow.\n");
            return; // Return early to avoid overflow
        }

        snprintf(new_name, sizeof(new_name), "%s/.%s", last_dir, strrchr(last_dir, '/') + 1);

        if (rename(last_dir, new_name) != 0) {
            fprintf(stderr, "Error renaming '%s' to '%s': %s\n", last_dir, new_name, strerror(errno));
        } else {
            printf("Directory renamed: %s -> %s\n", last_dir, new_name);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <attribute name> <starting path>\n", argv[0]);
        return 1;
    }

    const char *attr = argv[1];
    const char *start_dir = argv[2];

    printf("Starting search in directory '%s' with tag '%s'\n", start_dir, attr);
    process_files(start_dir, attr);

    return 0;
}
