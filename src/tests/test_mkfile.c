#include <CUnit/CUnit.h>
#include "../include/mkfile.h"

void test_create_file_with_valid_attributes(void) {
    char *tagName = "validTagName";
    char *tagValue = "validTagValue";
    char *filePath = "testfile.txt";

    int result = create_file_with_attribute(tagName, tagValue, filePath);

    CU_ASSERT_EQUAL(result, 0);

    // Verify that it worked
    char value[MAX_ATTR_VALUE_SIZE];
    ssize_t len = getxattr("testfile.txt", "user.validTagName", value, MAX_ATTR_VALUE_SIZE);
    CU_ASSERT(len > 0);
    value[len] = '\0';  // Ensure null-termination
    CU_ASSERT_STRING_EQUAL(value, "validTagValue");
}

void test_missing_tagName(void) {
    char *tagName = NULL;
    char *tagValue = "validTagValue";
    char *filePath = "testfile.txt";

    int result = create_file_with_attribute(tagName, tagValue, filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void test_missing_tagValue(void) {
    char *tagName = "validTagName";
    char *tagValue = NULL;
    char *filePath = "testfile.txt";

    int result = create_file_with_attribute(tagName, tagValue, filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void test_missing_filePath(void) {
    char *tagName = "validTagName";
    char *tagValue = "validTagValue";
    char *filePath = NULL;

    int result = create_file_with_attribute(tagName, tagValue, filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void add_mkfile_tests(CU_pSuite suite) {
    CU_add_test(suite, "test_create_file_with_valid_attributes", test_create_file_with_valid_attributes);
    CU_add_test(suite, "test_missing_tagName", test_missing_tagName);
    CU_add_test(suite, "test_missing_tagValue", test_missing_tagValue);
    CU_add_test(suite, "test_missing_filePath", test_missing_filePath);
}
