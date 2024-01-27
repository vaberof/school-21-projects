#include "s21_to_lower_test.h"

#include "../s21_string.h"

START_TEST(test_s21_to_lower) {
  const char* str_s21_to_lower = "HELLO MY NAME IS Linus Tovalds";
  char* expected_str = "hello my name is linus tovalds";
  char* result = s21_to_lower(str_s21_to_lower);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_with_empty_strings) {
  const char* str_s21_to_lower = "";
  char* expected_str = "";
  char* result = s21_to_lower(str_s21_to_lower);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_with_null_string) {
  const char* str_s21_to_lower = NULL;
  char* expected_str = NULL;
  char* result = s21_to_lower(str_s21_to_lower);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

Suite* create_s21_to_lower_suite(void) {
  Suite* s21_to_lower_suite;
  TCase* tc_core;

  s21_to_lower_suite = suite_create("s21_to_lower");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_to_lower);
  tcase_add_test(tc_core, test_s21_to_lower_with_empty_strings);
  tcase_add_test(tc_core, test_s21_to_lower_with_null_string);

  suite_add_tcase(s21_to_lower_suite, tc_core);

  return s21_to_lower_suite;
}

int run_s21_to_lower_suite() {
  int tests_number_failed = 0;

  Suite* s21_to_lower_suite;
  SRunner* s21_to_lower_suite_srunner;

  s21_to_lower_suite = create_s21_to_lower_suite();
  s21_to_lower_suite_srunner = srunner_create(s21_to_lower_suite);

  srunner_set_fork_status(s21_to_lower_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_to_lower_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_to_lower_suite_srunner);
  srunner_free(s21_to_lower_suite_srunner);

  return tests_number_failed;
}