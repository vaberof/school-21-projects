#include "s21_strncpy_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strncpy) {
  char dest_1[40] = "source_string";
  char dest_2[40] = "source_string";
  char src_1[40] = "append_part";
  char src_2[40] = "append_part";
  size_t n = 7;

  ck_assert_str_eq(s21_strncpy(dest_1, src_1, n), strncpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_first_string_has_more_length) {
  char dest_1[14] = "source_string";
  char dest_2[14] = "source_string";
  char src_1[12] = "append_part";
  char src_2[12] = "append_part";
  size_t n = 14;

  ck_assert_str_eq(s21_strncpy(dest_1, src_1, n), strncpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_first_string_is_empty) {
  char dest_1[10] = "";
  char dest_2[10] = "";
  char src_1[10] = "append_";
  char src_2[10] = "append_";
  size_t n = 12;

  ck_assert_str_eq(s21_strncpy(dest_1, src_1, n), strncpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_second_string_is_empty) {
  char dest_1[10] = "append_";
  char dest_2[10] = "append_";
  char src_1[10] = "";
  char src_2[10] = "";
  size_t n = 12;

  ck_assert_str_eq(s21_strncpy(dest_1, src_1, n), strncpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_second_string_has_more_length) {
  char dest_1[10] = "append_";
  char dest_2[10] = "append_";
  char src_1[12] = "source__";
  char src_2[12] = "source__";
  size_t n = 14;

  ck_assert_str_eq(s21_strncpy(dest_1, src_1, n), strncpy(dest_2, src_2, n));
}
END_TEST

Suite *create_s21_strncpy_suite(void) {
  Suite *s21_strncpy_suite;
  TCase *tc_core;

  s21_strncpy_suite = suite_create("s21_strncpy");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strncpy_first_string_has_more_length);
  tcase_add_test(tc_core, test_s21_strncpy_second_string_has_more_length);
  tcase_add_test(tc_core, test_s21_strncpy_first_string_is_empty);
  tcase_add_test(tc_core, test_s21_strncpy_second_string_is_empty);

  suite_add_tcase(s21_strncpy_suite, tc_core);

  return s21_strncpy_suite;
}

int run_s21_strncpy_suite() {
  int tests_number_failed = 0;

  Suite *s21_strncpy_suite;
  SRunner *s21_strncpy_suite_srunner;

  s21_strncpy_suite = create_s21_strncpy_suite();
  s21_strncpy_suite_srunner = srunner_create(s21_strncpy_suite);

  srunner_set_fork_status(s21_strncpy_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strncpy_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_strncpy_suite_srunner);
  srunner_free(s21_strncpy_suite_srunner);

  return tests_number_failed;
}