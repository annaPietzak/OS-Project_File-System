#include "include/isValidString.h"

// Function to check if a string contains only alphanumeric characters (a-zA-Z0-9_)
int is_valid_string(const char *str) {
    while (*str) {
        if (!isalnum((unsigned char)*str) && *str != '_') {
            return 1;  // Invalid character found
        }
        str++;
    }
    return 0;  // All characters are valid
}
