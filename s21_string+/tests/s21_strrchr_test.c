#include "s21_strrchr_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strrchr) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  int character = 'o';

  ck_assert_str_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

START_TEST(test_s21_strrchr_int) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  int character = 100;  // d

  ck_assert_str_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

START_TEST(test_s21_strrchr_capital_character) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  int character = 72;  // H

  ck_assert_str_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

START_TEST(test_s21_strrchr_no_matches) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  int character = 1000;

  ck_assert_ptr_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

START_TEST(test_s21_strrchr_string_end_character) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  int character = 0;  // \0

  ck_assert_str_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

START_TEST(test_s21_strrchr_empty_string) {
  const char str1[20] = "";
  const char str2[20] = "";
  int character = 72;  // \H

  ck_assert_ptr_eq(s21_strrchr(str1, character), strrchr(str2, character));
}
END_TEST

Suite *create_s21_strrchr_suite(void) {
  Suite *s21_strrchr_suite;
  TCase *tc_core;

  s21_strrchr_suite = suite_create("s21_strrchr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strrchr_int);
  tcase_add_test(tc_core, test_s21_strrchr_capital_character);
  tcase_add_test(tc_core, test_s21_strrchr_no_matches);
  tcase_add_test(tc_core, test_s21_strrchr_string_end_character);
  tcase_add_test(tc_core, test_s21_strrchr_empty_string);

  suite_add_tcase(s21_strrchr_suite, tc_core);

  return s21_strrchr_suite;
}

int run_s21_strrchr_suite() {
  int tests_number_failed = 0;

  Suite *s21_strrchr_suite;
  SRunner *s21_strrchr_suite_srunner;

  s21_strrchr_suite = create_s21_strrchr_suite();
  s21_strrchr_suite_srunner = srunner_create(s21_strrchr_suite);

  srunner_set_fork_status(s21_strrchr_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strrchr_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strrchr_suite_srunner);
  srunner_free(s21_strrchr_suite_srunner);

  return tests_number_failed;
}