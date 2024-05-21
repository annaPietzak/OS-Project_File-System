#include "include/deleteTag.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <tag_name> <file_path>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *filePath = argv[2];

    // Check if combined length of "user." and tagName is longer than allowed
    if (check_tag_name(tagName) == 1) {
        fprintf(stderr, "Error: The total length of 'user.%s' exceeds the limit of %d characters\n",
                tagName, MAX_ATTR_NAME_SIZE - 1);
        return 1;
    }

    // Check if the tagName contains any non-alphanumeric characters
    if (is_valid_string(tagName) == 1) {
        fprintf(stderr, "Error: Tag name '%s' contains invalid characters. "
                        "Only alphanumeric and underscores are allowed.\n", tagName);
        return 1;
    }

    delete_tag_from_file(tagName, filePath);

    // Print when it was successful
    printf("Tag %s removed successfully from file %s\n", tagName, filePath);

    return 0;
}