#include "s21_trim_test.h"

#include "../s21_string.h"

START_TEST(test_s21_trim) {
  const char* src_s21_trim = "*** Hello Tovalds ***";
  char* s21_trim_chars = "* ";
  char* expected_str = "Hello Tovalds";
  char* result = s21_trim(src_s21_trim, s21_trim_chars);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_with_null_strings) {
  const char* src_s21_trim = "*** Hello Tovalds ***";
  char* s21_trim_chars = NULL;
  char* expected_str = NULL;
  char* result = s21_trim(src_s21_trim, s21_trim_chars);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST
//
// START_TEST(test_s21_trim_with_null_string) {
//    const char* src_s21_trim = NULL;
//    char* str_s21_trim = "Hello Linus Tovalds";
//    char* expected_str = NULL;
//    size_t index = 0;
//    char* result = s21_trim(src_s21_trim, str_s21_trim, index);
//    ck_assert_str_eq(result, expected_str);
//    free(result);
//}
// END_TEST

Suite* create_s21_trim_suite(void) {
  Suite* s21_trim_suite;
  TCase* tc_core;

  s21_trim_suite = suite_create("s21_trim");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_trim);
  tcase_add_test(tc_core, test_s21_trim_with_null_strings);
  // tcase_add_test(tc_core, test_s21_trim_with_null_string);

  suite_add_tcase(s21_trim_suite, tc_core);

  return s21_trim_suite;
}

int run_s21_trim_suite() {
  int tests_number_failed = 0;

  Suite* s21_trim_suite;
  SRunner* s21_trim_suite_srunner;

  s21_trim_suite = create_s21_trim_suite();
  s21_trim_suite_srunner = srunner_create(s21_trim_suite);

  srunner_set_fork_status(s21_trim_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_trim_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_trim_suite_srunner);
  srunner_free(s21_trim_suite_srunner);

  return tests_number_failed;
}