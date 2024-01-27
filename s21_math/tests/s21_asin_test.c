#include "s21_asin_test.h"

START_TEST(test_s21_asin_positive_double_less_one) {
  long double s21_asin_res = s21_asin(0.583053);
  double asin_res = asin(0.583053);
  ck_assert_ldouble_eq_tol(s21_asin_res, asin_res, 1e-6);
}
END_TEST

START_TEST(test_s21_asin_positive_double) {
  long double s21_asin_res = s21_asin(351.341);
  double asin_res = asin(351.341);
  ck_assert_double_nan(s21_asin_res);
  ck_assert_double_nan(asin_res);
}
END_TEST

START_TEST(test_s21_asin_zero) {
  long double s21_asin_res = s21_asin(0);
  double asin_res = asin(0);
  ck_assert_ldouble_eq_tol(s21_asin_res, asin_res, 1e-6);
}
END_TEST

START_TEST(test_s21_asin_negative_double_greater_minus_one) {
  long double s21_asin_res = s21_asin(-0.0213);
  double asin_res = asin(-0.0213);
  ck_assert_ldouble_eq_tol(s21_asin_res, asin_res, 1e-6);
}
END_TEST

START_TEST(test_s21_asin_negative_double) {
  long double s21_asin_res = s21_asin(-2187.54);
  double asin_res = asin(-2187.54);
  ck_assert_double_nan(s21_asin_res);
  ck_assert_double_nan(asin_res);
}
END_TEST

START_TEST(test_s21_asin_positive_one) {
  long double s21_asin_res = s21_asin(1);
  double asin_res = asin(1);
  ck_assert_ldouble_eq_tol(s21_asin_res, asin_res, 1e-6);
}
END_TEST

START_TEST(test_s21_asin_negative_one) {
  long double s21_asin_res = s21_asin(-1);
  double asin_res = asin(-1);
  ck_assert_ldouble_eq_tol(s21_asin_res, asin_res, 1e-6);
}
END_TEST

Suite* create_s21_asin_suite(void) {
  Suite* s21_asin_suite;
  TCase* tc_core;

  s21_asin_suite = suite_create("s21_asin");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_asin_positive_double_less_one);
  tcase_add_test(tc_core, test_s21_asin_positive_double);
  tcase_add_test(tc_core, test_s21_asin_zero);
  tcase_add_test(tc_core, test_s21_asin_negative_double_greater_minus_one);
  tcase_add_test(tc_core, test_s21_asin_negative_double);
  tcase_add_test(tc_core, test_s21_asin_positive_one);
  tcase_add_test(tc_core, test_s21_asin_negative_one);

  suite_add_tcase(s21_asin_suite, tc_core);

  return s21_asin_suite;
}

int run_s21_asin_suite() {
  int tests_number_failed = 0;

  Suite* s21_asin_suite;
  SRunner* s21_asin_suite_srunner;

  s21_asin_suite = create_s21_asin_suite();
  s21_asin_suite_srunner = srunner_create(s21_asin_suite);

  srunner_set_fork_status(s21_asin_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_asin_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_asin_suite_srunner);
  srunner_free(s21_asin_suite_srunner);

  return tests_number_failed;
}