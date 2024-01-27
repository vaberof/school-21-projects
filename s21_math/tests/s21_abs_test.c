#include "s21_abs_test.h"

START_TEST(test_s21_abs_positive_int) {
  int s21_abs_res = s21_abs(8194);
  int abs_res = abs(8194);
  ck_assert_int_eq(s21_abs_res, abs_res);
}
END_TEST

START_TEST(test_s21_abs_negative_int) {
  int s21_abs_res = s21_abs(-128514);
  int abs_res = abs(-128514);
  ck_assert_int_eq(s21_abs_res, abs_res);
}
END_TEST

START_TEST(test_s21_abs_zero) {
  int s21_abs_res = s21_abs(-128514);
  int abs_res = abs(-128514);
  ck_assert_int_eq(s21_abs_res, abs_res);
}
END_TEST

Suite* create_s21_abs_suite(void) {
  Suite* s21_abs_suite;
  TCase* tc_core;

  s21_abs_suite = suite_create("s21_abs");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_abs_positive_int);
  tcase_add_test(tc_core, test_s21_abs_negative_int);
  tcase_add_test(tc_core, test_s21_abs_zero);

  suite_add_tcase(s21_abs_suite, tc_core);

  return s21_abs_suite;
}

int run_s21_abs_suite() {
  int tests_number_failed = 0;

  Suite* s21_abs_suite;
  SRunner* s21_abs_suite_srunner;

  s21_abs_suite = create_s21_abs_suite();
  s21_abs_suite_srunner = srunner_create(s21_abs_suite);

  srunner_set_fork_status(s21_abs_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_abs_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_abs_suite_srunner);
  srunner_free(s21_abs_suite_srunner);

  return tests_number_failed;
}