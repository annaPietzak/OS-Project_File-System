#include <CUnit/CUnit.h>
#include "../include/listAll.h"

void test_list_all_tags_success(void) {
    const char *filePath = "testfile_with_attrs.txt";
    const char *tagName = "user.validTagName";
    const char *tagValue = "validTagValue";

    FILE *file = fopen(filePath, "w");
    CU_ASSERT_PTR_NOT_NULL(file);
    fclose(file);
    setxattr(filePath, tagName, tagValue, strlen(tagValue), 0);

    int result = list_all_tags(filePath);

    CU_ASSERT_EQUAL(result, 0);
}

void test_list_all_tags_no_attributes(void) {
    const char *filePath = "testfile_no_attrs.txt";

    FILE *file = fopen(filePath, "w");
    CU_ASSERT_PTR_NOT_NULL(file);
    fclose(file);

    int result = list_all_tags(filePath);

    CU_ASSERT_EQUAL(result, 0);
}

void test_list_all_tags_non_existent_file(void) {
    const char *filePath = "non_existent_file.txt";

    int result = list_all_tags(filePath);

    CU_ASSERT_EQUAL(result, 1);
}

void add_listAll_tests(CU_pSuite suite) {
    CU_add_test(suite, "test_list_all_tags_success", test_list_all_tags_success);
    CU_add_test(suite, "test_list_all_tags_no_attributes", test_list_all_tags_no_attributes);
    CU_add_test(suite, "test_list_all_tags_non_existent_file", test_list_all_tags_non_existent_file);
}
