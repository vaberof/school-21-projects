#include "s21_floor_test.h"

START_TEST(test_s21_floor) {
  long double s21_floor_ret = s21_floor(3.8);
  long double floor_ret = floor(3.8);
  ck_assert_ldouble_eq(s21_floor_ret, floor_ret);
}
END_TEST

START_TEST(test_s21_floor_negative_args) {
  long double s21_floor_ret = s21_floor(-3.1);
  long double floor_ret = floor(-3.1);
  ck_assert_ldouble_eq(s21_floor_ret, floor_ret);
}
END_TEST

START_TEST(test_s21_floor_nan) {
  long double s21_floor_ret = s21_floor(NaN);
  long double floor_ret = floor(NaN);
  ck_assert_ldouble_nan(s21_floor_ret);
  ck_assert_ldouble_nan(floor_ret);
}
END_TEST

START_TEST(test_s21_floor_zero_args) {
  long double s21_floor_ret = s21_floor(0.0);
  long double floor_ret = floor(0.0);
  ck_assert_ldouble_eq(s21_floor_ret, floor_ret);
}
END_TEST

Suite* create_s21_floor_suite(void) {
  Suite* s21_floor_suite;
  TCase* tc_core;

  s21_floor_suite = suite_create("s21_floor");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_floor_negative_args);
  tcase_add_test(tc_core, test_s21_floor_zero_args);
  tcase_add_test(tc_core, test_s21_floor_nan);

  suite_add_tcase(s21_floor_suite, tc_core);

  return s21_floor_suite;
}

int run_s21_floor_suite() {
  int tests_number_failed = 0;

  Suite* s21_floor_suite;
  SRunner* s21_floor_suite_srunner;

  s21_floor_suite = create_s21_floor_suite();
  s21_floor_suite_srunner = srunner_create(s21_floor_suite);

  srunner_set_fork_status(s21_floor_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_floor_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_floor_suite_srunner);
  srunner_free(s21_floor_suite_srunner);

  return tests_number_failed;
}