#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <Department_store_header.h>
#define PROJECT_NAME    "Department_store_management_system"

/* Prototypes for all the test functions */
void test_Add_goods();
void test_Edit_goods();
void test_Calculate_bill();
void test_Display_goods();
void test_Search_goods();

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "Add_goods", test_Add_goods);
  CU_add_test(suite, "Edit_goods", test_Edit_goods);
  CU_add_test(suite, "Calculate_bill", test_Calculate_bill);
  CU_add_test(suite, "Display_goods", test_Display_good);
  CU_add_test(suite, "Search_goods", test_Search_goods);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */
void test_Add_goods(){
  CU_ASSERT(1 == Add_goods());
}

void test_Edit_goods() {
  CU_ASSERT(1 == Edit_goods());
}

void test_Calculate_bill() {
  CU_ASSERT(1 == Calculate_bill());
}

void test_Display_goods() {
  CU_ASSERT(1 == Display_goods());
}
void test_Search_goods() {
  CU_ASSERT(1 == Search_goods());
}
