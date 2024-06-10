#include "include/checkLengthName.h"

/**
 * This function checks the length of user. + tagName since it's allowed to be longer than 255
 * characters
 * @param tagName name of the tag that should be checked
 * @return 0 or 1 depending on if the name is valid or not
 */

int check_tag_name(const char * tagName) {
    size_t fullTagNameLength = strlen("user.") + strlen(tagName);

    if (fullTagNameLength >= MAX_ATTR_NAME_SIZE) {
        return 1;
    }
    return 0;
}
