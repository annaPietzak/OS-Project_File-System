#include <CUnit/CUnit.h>
#include "../include/deleteTag.h"

void test_delete_tag_success(void) {
    const char *tagName = "validTagName";
    const char *filePath = "testfile2.txt";

    int result = delete_tag_from_file(tagName, filePath);

    CU_ASSERT_EQUAL(result, 0);
}

void test_delete_tag_missing_tagName(void) {
    const char *tagName = NULL;
    const char *filePath = "testfile2.txt";

    int result = delete_tag_from_file(tagName, filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void test_delete_tag_missing_filePath(void) {
    const char *tagName = "validTagName";
    const char *filePath = NULL;

    int result = delete_tag_from_file(tagName, filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void test_delete_tag_non_existing_attribute(void) {
    const char *tagName = "nonExistingTagName";
    const char *filePath = "testfile2.txt";

    int result = delete_tag_from_file(tagName, filePath);

    CU_ASSERT_EQUAL(result, 0);
}

void add_deleteTag_tests(CU_pSuite suite) {
    CU_add_test(suite, "test_delete_tag_success", test_delete_tag_success);
    CU_add_test(suite, "test_delete_tag_missing_tagName", test_delete_tag_missing_tagName);
    CU_add_test(suite, "test_delete_tag_missing_filePath", test_delete_tag_missing_filePath);
    CU_add_test(suite, "test_delete_tag_non_existing_attribute", test_delete_tag_non_existing_attribute);
}
