#include "s21_strncat_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strncat_append_nonempty_string) {
  char dest_1[40] = "source_string";
  char dest_2[40] = "source_string";
  char src_1[40] = "_append_part";
  char src_2[40] = "_append_part";
  size_t n = 5;

  ck_assert_str_eq(s21_strncat(dest_1, src_1, n), strncat(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncat_append_empty_string) {
  char dest_1[20] = "source_string";
  char dest_2[20] = "source_string";
  char src_1[40] = "";
  char src_2[40] = "";

  size_t n = 5;

  ck_assert_str_eq(s21_strncat(dest_1, src_1, n), strncat(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncat_append_to_empty_string) {
  char dest_1[20] = "";
  char dest_2[20] = "";
  char src_1[40] = "to_copy";
  char src_2[40] = "to_copy";

  size_t n = 5;

  ck_assert_str_eq(s21_strncat(dest_1, src_1, n), strncat(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_strncat_try_overflow_buffer) {
  char dest_1[20] = "source_string";
  char dest_2[20] = "source_string";
  char src_1[40] = "_append_part";
  char src_2[40] = "_append_part";

  size_t n = 100;

  ck_assert_str_eq(s21_strncat(dest_1, src_1, n), strncat(dest_2, src_2, n));
}
END_TEST

Suite *create_s21_strncat_suite(void) {
  Suite *s21_strncat_suite;
  TCase *tc_core;

  s21_strncat_suite = suite_create("s21_strncat");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strncat_append_nonempty_string);
  tcase_add_test(tc_core, test_s21_strncat_append_empty_string);
  tcase_add_test(tc_core, test_s21_strncat_try_overflow_buffer);
  tcase_add_test(tc_core, test_s21_strncat_append_to_empty_string);

  suite_add_tcase(s21_strncat_suite, tc_core);

  return s21_strncat_suite;
}

int run_s21_strncat_suite() {
  int tests_number_failed = 0;

  Suite *s21_strncat_suite;
  SRunner *s21_strncat_suite_srunner;

  s21_strncat_suite = create_s21_strncat_suite();
  s21_strncat_suite_srunner = srunner_create(s21_strncat_suite);

  srunner_set_fork_status(s21_strncat_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strncat_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strncat_suite_srunner);
  srunner_free(s21_strncat_suite_srunner);

  return tests_number_failed;
}
