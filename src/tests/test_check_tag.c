#include <CUnit/CUnit.h>
#include "../include/checkLengthName.h"
#include "../include/checkLengthValue.h"

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

void test_check_tag_value_valid(void) {
    // A valid tag name that should not trigger an error
    const char *validTagValue = "validTagName";
    CU_ASSERT_EQUAL(check_tag_value(validTagValue), 0);
}

void test_check_tag_value_too_long(void) {
    // A tag value that exceeds the maximum length
    char longTagName[MAX_ATTR_VALUE_SIZE + 1];
    memset(longTagName, 'a', sizeof(longTagName) - 1);
    longTagName[sizeof(longTagName) - 1] = '\0';
    CU_ASSERT_EQUAL(check_tag_value(longTagName), 1);
}

// Function to add all the tests to a suite
void add_check_tag_tests(CU_pSuite suite) {
    CU_add_test(suite, "test_check_tag_name_valid", test_check_tag_name_valid);
    CU_add_test(suite, "test_check_tag_name_too_long", test_check_tag_name_too_long);
    CU_add_test(suite, "test_check_tag_value_valid", test_check_tag_value_valid);
    CU_add_test(suite, "test_check_tag_value_too_long", test_check_tag_value_too_long);
}
