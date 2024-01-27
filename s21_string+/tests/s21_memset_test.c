#include "s21_memset_test.h"

#include "../s21_string.h"

START_TEST(test_s21_memset_set_char_in_nonempty_string) {
  char str1[20] = "source_string";
  char str2[20] = "source_string";
  char symbol = 'a';
  size_t n = 5;

  ck_assert_str_eq(s21_memset(str1, symbol, n), memset(str2, symbol, n));
}
END_TEST

START_TEST(test_s21_memset_set_char_in_empty_string) {
  char str1[10] = "";
  char str2[10] = "";
  char symbol = 'a';
  size_t n = 5;

  ck_assert_str_eq(s21_memset(str1, symbol, n), memset(str2, symbol, n));
}
END_TEST

START_TEST(test_s21_memset_set_char_in_first_zero_bytes) {
  char str1[10] = "test";
  char str2[10] = "test";
  char symbol = 'a';
  size_t n = 0;

  ck_assert_str_eq(s21_memset(str1, symbol, n), memset(str2, symbol, n));
}
END_TEST

Suite *create_s21_memset_suite(void) {
  Suite *s21_memset_suite;
  TCase *tc_core;

  s21_memset_suite = suite_create("s21_memset");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_memset_set_char_in_nonempty_string);
  tcase_add_test(tc_core, test_s21_memset_set_char_in_empty_string);
  tcase_add_test(tc_core, test_s21_memset_set_char_in_first_zero_bytes);

  suite_add_tcase(s21_memset_suite, tc_core);

  return s21_memset_suite;
}

int run_s21_memset_suite() {
  int tests_number_failed = 0;

  Suite *s21_memset_suite;
  SRunner *s21_memset_suite_srunner;

  s21_memset_suite = create_s21_memset_suite();
  s21_memset_suite_srunner = srunner_create(s21_memset_suite);

  srunner_set_fork_status(s21_memset_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_memset_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_memset_suite_srunner);
  srunner_free(s21_memset_suite_srunner);

  return tests_number_failed;
}