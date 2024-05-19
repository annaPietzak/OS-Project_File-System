#include <CUnit/CUnit.h>
#include "../include/checkLengthName.h"

void test_check_tag_name_valid(void) {
    // A valid tag name that should not trigger an error
    const char *validTagName = "validTagName";
    CU_ASSERT_EQUAL(check_tag_name(validTagName), 0);
}

void test_check_tag_name_too_long(void) {
    // A tag name that exceeds the maximum length
    char longTagName[MAX_ATTR_NAME_SIZE - strlen("user.") + 1];
    memset(longTagName, 'a', sizeof(longTagName) - 1);
    longTagName[sizeof(longTagName) - 1] = '\0';
    CU_ASSERT_EQUAL(check_tag_name(longTagName), 1);
}

// Function to add all the tests to a suite
void add_check_tag_name_tests(CU_pSuite suite2) {
    CU_add_test(suite2, "test_check_tag_name_valid", test_check_tag_name_valid);
    CU_add_test(suite2, "test_check_tag_name_too_long", test_check_tag_name_too_long);
}
