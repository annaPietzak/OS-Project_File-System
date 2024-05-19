#include "include/checkLengthValue.h"

// Check length of tagValue
int check_tag_value(const char * tagValue) {
    if (strlen(tagValue) >= MAX_ATTR_VALUE_SIZE) {
        return 1;
    }
    return 0;
}
