#include "include/checkLengthValue.h"

/**
 * This function checks the length of the entered value, which will be associated with the name.
 * The length isn't allowed to be longer than 3072 characters
 * @param tagValue value of the tag that should be checked
 * @return 0 or 1 depending on if the tagValue is allowed or not
 */

// Check length of tagValue
int check_tag_value(const char * tagValue) {
    if (strlen(tagValue) >= MAX_ATTR_VALUE_SIZE) {
        return 1;
    }
    return 0;
}
