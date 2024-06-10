#include "include/addNewTag.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <tag_name> <tag_value>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];
    char *tagValue = argv[2];
   
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

    // Check if combined length of "user." and tagName is longer than allowed
    if (check_tag_value(tagValue) == 1) {
        fprintf(stderr, "Error: The total length of '%s' exceeds the limit of %d characters\n",
                tagValue, MAX_ATTR_NAME_SIZE - 1);
        return 1;
    }

    // Check if the tagName contains any non-alphanumeric characters
    if (is_valid_string(tagValue) == 1) {
        fprintf(stderr, "Error: Tag value '%s' contains invalid characters. "
                        "Only alphanumeric and underscores are allowed.\n", tagValue);
        return 1;
    }

    if (check_if_tag_is_known(tagName, tagValue) != 1) {
        fprintf(stderr, "This tag is already in the filesystem.\n");
        return 0;
    }

    add_new_tag(tagName, tagValue);

    // Print when it was successful
    printf("Tag %s %s added successfully\n", tagName, tagValue);

    return 0;
}