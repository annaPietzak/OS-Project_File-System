#include "include/checkLengthValue.h"

// Check length of tagValue
int check_tag_value(const char * tagValue) {
    if (strlen(tagValue) >= MAX_ATTR_VALUE_SIZE) {
        fprintf(stderr, "Error: The length of the tag_value exceeds the limit of %d characters\n",
                MAX_ATTR_VALUE_SIZE - 1);
        return 1;
    }
    return 0;
}
