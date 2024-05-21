#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void add_is_valid_string_tests(CU_pSuite suite);
void add_check_tag_tests(CU_pSuite suite);
void add_mkfile_tests(CU_pSuite suite);
void add_deleteTag_tests(CU_pSuite suite);
void add_listAll_tests(CU_pSuite suite);

// Setup code
int global_setup(void) {
    printf("Setting up the environment\n");
    return 0;
}

// Teardown code
int global_teardown(void) {
    // Clean up files
    printf("\nRemoving everything that was created\n");
    remove("testfile.txt"); // test_mkfile
    remove("testfile2.txt"); // test_deleteTag
    remove("testfile_with_attrs.txt"); // test_listAll
    remove("testfile_no_attrs.txt"); // test_listAll
    return 0;
}

int main() {
    // Initialize the CUnit test registry
    printf("Initializing the CUnit test registry\n");
    if (CUE_SUCCESS != CU_initialize_registry()) {
        fprintf(stderr, "Failed to initialize the CUnit test registry: %s\n",
                strerror(errno));
        return CU_get_error();
    }

    // Add suite for is_valid_string tests
    printf("Adding suite for is_valid_string\n");
    CU_pSuite pSuite1 = CU_add_suite("Suite for is_valid_string", global_setup, global_teardown);
    if (NULL == pSuite1) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_is_valid_string_tests(pSuite1);

    // Add suite for check_tag_name tests
    printf("Adding suite for check_tag\n");
    CU_pSuite pSuite2 = CU_add_suite("Suite for check_tag", global_setup, global_teardown);
    if (NULL == pSuite2) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_check_tag_tests(pSuite2);

    printf("Adding suite for test_mkfile\n");
    // Add suite for test_mkfile_main tests
    CU_pSuite pSuite3 = CU_add_suite("Suite for test_mkfile", global_setup, global_teardown);
    if (NULL == pSuite3) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_mkfile_tests(pSuite3);

    printf("Adding suite for test_deleteTag\n");
    // Add suite for test_deleteTag tests
    CU_pSuite pSuite4 = CU_add_suite("Suite for test_deleteTag", global_setup, global_teardown);
    if (NULL == pSuite4) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_deleteTag_tests(pSuite4);

    printf("Adding suite for test_listAll");
    // Add suite for test_listAll tests
    CU_pSuite pSuite5 = CU_add_suite("Suite for test_listAll", global_setup, global_teardown);
    if (NULL == pSuite5) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    add_listAll_tests(pSuite5);

    // Run all tests using the CUnit Basic interface
    printf("Running all tests\n");
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    printf("Tests completed\n");
    return CU_get_error();
}