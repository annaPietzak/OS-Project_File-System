#include <CUnit/CUnit.h>
#include "../include/isValidString.h"

void test_is_valid_string_valid(void) {
    const char *validStr = "ValidString123";
    CU_ASSERT_EQUAL(is_valid_string(validStr), 0);
}

void test_is_valid_string_invalid(void) {
    const char *invalidStr = "Invalid$String";
    CU_ASSERT_EQUAL(is_valid_string(invalidStr), 1);
}

void test_is_valid_string_empty(void) {
    const char *emptyStr = "";
    CU_ASSERT_EQUAL(is_valid_string(emptyStr), 0);
}

void test_is_valid_string_edge_cases(void) {
    const char *edgeStr1 = "_underscored_string";
    const char *edgeStr2 = "12345";
    CU_ASSERT_EQUAL(is_valid_string(edgeStr1), 0);
    CU_ASSERT_EQUAL(is_valid_string(edgeStr2), 0);
}

void add_is_valid_string_tests(CU_pSuite suite) {
    CU_add_test(suite, "test_is_valid_string_valid", test_is_valid_string_valid);
    CU_add_test(suite, "test_is_valid_string_invalid", test_is_valid_string_invalid);
    CU_add_test(suite, "test_is_valid_string_empty", test_is_valid_string_empty);
    CU_add_test(suite, "test_is_valid_string_edge_cases", test_is_valid_string_edge_cases);
}