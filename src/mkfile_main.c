#include "include/mkfile.h"

int main (int argc, char * argv[]) {
    if (argc < 4) {
        printf("Usage: %s <tag_name> <tag_value> <file_path>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *tagValue = argv[2];
    char *filePath = argv[3];

    // Check if combined length of "user." and tagName is longer than allowed
    if (check_tag_name(tagName) == 1) {
        fprintf(stderr, "Error: The total length of the tag_name exceeds the limit of %d characters\n",
                (MAX_ATTR_NAME_SIZE - 1 - strlen("user.")));
        return 1;
    }

    if (check_tag_value(tagValue) == 1) {
        fprintf(stderr, "Error: The length of the tag_value exceeds the limit of %d characters\n",
                MAX_ATTR_VALUE_SIZE - 1);
        return 1;
    }

    if (check_if_tag_is_known(tagName, tagValue) == 1) {
        fprintf(stderr, "This tag is not yet used in the filesystem. Tags can be added to the filesystem with eftas addTag <tagName> <tagValue>\n");
        return 1;
    }

    // Check if the tagName contains any non-alphanumeric characters
    if (is_valid_string(tagName) == 1) {
        fprintf(stderr, "Error: Tag name '%s' contains invalid characters. "
                        "Only alphanumeric and underscores are allowed.\n", tagName);
        return 1;
    }

    // Check if the tagValue contains any non-alphanumeric characters
    if (is_valid_string(tagValue) == 1) {
        fprintf(stderr, "Error: Tag value '%s' contains invalid characters. "
                        "Only alphanumeric and underscores are allowed.\n", tagValue);
        return 1;
    }
    
    //check if filepath is directory
    if (check_file_path(filePath) == 1) {
        fprintf(stderr, "Error: File path '%s' points to a directory. "
                        "mkfile is only used for files.\n", filePath);
        return 1;
    }

    create_file_with_attribute(tagName, tagValue, filePath);
    
    // Print when it was successful
    printf("Tag %s set successfully for file %s with name %s\n", tagValue, filePath, tagName);
    return 0;
}
