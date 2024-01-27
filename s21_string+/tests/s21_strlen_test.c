#include "s21_strlen_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strlen) {
  const char str[20] = "source_string";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_empty_string) {
  const char str[20] = "";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_string_with_spaces) {
  const char str[20] = "               ";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_string_with_one_symbol) {
  const char str[20] = "a";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_string_with_deims) {
  const char str[20] = "one,two,three";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_string_with_special_symbols) {
  const char str[20] = "@#$^";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
  const char str[20] = "@#$^";

  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *create_s21_strlen_suite(void) {
  Suite *s21_strlen_suite;
  TCase *tc_core;

  s21_strlen_suite = suite_create("s21_strlen");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strlen_empty_string);
  tcase_add_test(tc_core, test_s21_strlen_string_with_spaces);
  tcase_add_test(tc_core, test_s21_strlen_string_with_one_symbol);
  tcase_add_test(tc_core, test_s21_strlen_string_with_deims);
  tcase_add_test(tc_core, test_s21_strlen_string_with_special_symbols);
  tcase_add_test(tc_core, test_s21_strlen_long_string);

  suite_add_tcase(s21_strlen_suite, tc_core);

  return s21_strlen_suite;
}

int run_s21_strlen_suite() {
  int tests_number_failed = 0;

  Suite *s21_strlen_suite;
  SRunner *s21_strlen_suite_srunner;

  s21_strlen_suite = create_s21_strlen_suite();
  s21_strlen_suite_srunner = srunner_create(s21_strlen_suite);

  srunner_set_fork_status(s21_strlen_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strlen_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strlen_suite_srunner);
  srunner_free(s21_strlen_suite_srunner);

  return tests_number_failed;
}