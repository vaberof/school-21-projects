#include "s21_to_upper_test.h"

#include "../s21_string.h"

START_TEST(test_s21_to_upper) {
  const char* str_s21_to_upper = "hello my name is Linus Tovalds";
  char* expected_str = "HELLO MY NAME IS LINUS TOVALDS";
  char* result = s21_to_upper(str_s21_to_upper);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_with_empty_strings) {
  const char* str_s21_to_upper = "";
  char* expected_str = "";
  char* result = s21_to_upper(str_s21_to_upper);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_with_null_string) {
  const char* str_s21_to_upper = NULL;
  char* expected_str = NULL;
  char* result = s21_to_upper(str_s21_to_upper);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

Suite* create_s21_to_upper_suite(void) {
  Suite* s21_to_upper_suite;
  TCase* tc_core;

  s21_to_upper_suite = suite_create("s21_to_upper");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_to_upper);
  tcase_add_test(tc_core, test_s21_to_upper_with_empty_strings);
  tcase_add_test(tc_core, test_s21_to_upper_with_null_string);

  suite_add_tcase(s21_to_upper_suite, tc_core);

  return s21_to_upper_suite;
}

int run_s21_to_upper_suite() {
  int tests_number_failed = 0;

  Suite* s21_to_upper_suite;
  SRunner* s21_to_upper_suite_srunner;

  s21_to_upper_suite = create_s21_to_upper_suite();
  s21_to_upper_suite_srunner = srunner_create(s21_to_upper_suite);

  srunner_set_fork_status(s21_to_upper_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_to_upper_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_to_upper_suite_srunner);
  srunner_free(s21_to_upper_suite_srunner);

  return tests_number_failed;
}