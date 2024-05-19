#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// Function declarations to add tests from different modules
void add_is_valid_string_tests(CU_pSuite suite);
void add_check_tag_tests(CU_pSuite suite);

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Add suite for is_valid_string tests
    CU_pSuite pSuite1 = CU_add_suite("Suite for is_valid_string", NULL, NULL);
    if (NULL == pSuite1) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_is_valid_string_tests(pSuite1);

    // Add suite for check_tag_name tests
    CU_pSuite pSuite2 = CU_add_suite("Suite for check_tag", NULL, NULL);
    if (NULL == pSuite2) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_check_tag_tests(pSuite2);

    // Run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}