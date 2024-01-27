#include "s21_insert_test.h"

#include "../s21_string.h"

START_TEST(test_s21_insert) {
  const char* src_s21_insert = "Hello Tovalds";
  char* str_s21_insert = "Linus ";
  char* expected_str = "Hello Linus Tovalds";
  size_t index = 6;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_valid_start_index) {
  const char* src_s21_insert = "Hello Tovalds";
  char* str_s21_insert = "Linus ";
  char* expected_str = "Hello TovaldsLinus ";
  size_t index = 13;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_invalid_start_index) {
  const char* src_s21_insert = "Hello Tovalds";
  char* str_s21_insert = "Linus ";
  char* expected_str = NULL;
  size_t index = -6;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_in_empty_string) {
  const char* src_s21_insert = "";
  char* str_s21_insert = "Hello Linus Tovalds";
  char* expected_str = "Hello Linus Tovalds";
  size_t index = 0;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_str_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_in_empty_string_2) {
  const char* src_s21_insert = "";
  char* str_s21_insert = "Hello Linus Tovalds";
  char* expected_str = NULL;
  size_t index = 40;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_with_null_string) {
  const char* src_s21_insert = NULL;
  char* str_s21_insert = "Hello Linus Tovalds";
  char* expected_str = NULL;
  size_t index = 0;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_with_null_string_2) {
  const char* src_s21_insert = NULL;
  char* str_s21_insert = "Hello Linus Tovalds";
  char* expected_str = NULL;
  size_t index = 10;
  char* result = s21_insert(src_s21_insert, str_s21_insert, index);
  ck_assert_ptr_eq(result, expected_str);
  free(result);
}
END_TEST

Suite* create_s21_insert_suite(void) {
  Suite* s21_insert_suite;
  TCase* tc_core;

  s21_insert_suite = suite_create("s21_insert");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_insert);
  tcase_add_test(tc_core, test_s21_insert_invalid_start_index);
  tcase_add_test(tc_core, test_s21_insert_valid_start_index);
  tcase_add_test(tc_core, test_s21_insert_in_empty_string);
  tcase_add_test(tc_core, test_s21_insert_with_null_string);
  tcase_add_test(tc_core, test_s21_insert_in_empty_string_2);
  tcase_add_test(tc_core, test_s21_insert_with_null_string_2);

  suite_add_tcase(s21_insert_suite, tc_core);

  return s21_insert_suite;
}

int run_s21_insert_suite() {
  int tests_number_failed = 0;

  Suite* s21_insert_suite;
  SRunner* s21_insert_suite_srunner;

  s21_insert_suite = create_s21_insert_suite();
  s21_insert_suite_srunner = srunner_create(s21_insert_suite);

  srunner_set_fork_status(s21_insert_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_insert_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_insert_suite_srunner);
  srunner_free(s21_insert_suite_srunner);

  return tests_number_failed;
}