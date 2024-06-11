#include "include/addNewTag.h"

/**
 * This is the main method for addNewTag.c. It first checks the tagName for length, validity and
 * if the tag is already in the tags.cvs file. If all are good, then it executes addnewTag.c
 * @param argc Used for checking the amount of arguments
 * @param argv tagName is one argument
 * @return 0 or 1 depending on if it worked or not
 */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <tag_name>\n", argv[0]);
        return 1;
    }
    char *tagName = argv[1];

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

    if (check_if_tag_is_known(tagName) != 1) {
        fprintf(stderr, "This tag is already in the filesystem.\n");
        return 0;
    }

    add_new_tag(tagName);

    // Print when it was successful
    printf("Tag %s added successfully\n", tagName);

    return 0;
}