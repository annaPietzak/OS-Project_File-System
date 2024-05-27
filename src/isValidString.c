#include "include/isValidString.h"

/**
 * This function checks, if either the tagName or the tagValue contain only alphanumeric characters (a-zA-Z0-9_).
 * @param str either tagName or tagValue
 * @return 0 or 1 depending on if the entered value has only alphanumeric characters or not
 */

int is_valid_string(const char *str) {
    while (*str) {
        if (!isalnum((unsigned char)*str) && *str != '_') {
            return 1;  // Invalid character found
        }
        str++;
    }
    return 0;  // All characters are valid
}
