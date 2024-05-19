#include "include/checkLengthName.h"

// Check if combined length of "user." and tagName is longer than allowed
int check_tag_name(const char * tagName) {
    size_t fullTagNameLength = strlen("user.") + strlen(tagName);

    if (fullTagNameLength >= MAX_ATTR_NAME_SIZE) {
        return 1;
    }
    return 0;
}
