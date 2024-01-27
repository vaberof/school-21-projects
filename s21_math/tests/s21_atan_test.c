#include "s21_atan_test.h"

START_TEST(test_s21_atan_positive_double) {
  long double s21_atan_res = s21_atan(0.58305341);
  double atan_res = atan(0.58305341);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-10);
}
END_TEST

START_TEST(test_s21_atan_negative_double) {
  long double s21_atan_res = s21_atan(-0.2940105910);
  double atan_res = atan(-0.2940105910);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-10);
}
END_TEST

START_TEST(test_s21_atan_zero) {
  long double s21_atan_res = s21_atan(0.0);
  double atan_res = atan(0.0);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-10);
}
END_TEST

START_TEST(test_s21_atan_small_double) {
  long double s21_atan_res = s21_atan(0.00000000000001);
  double atan_res = atan(0.00000000000001);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-10);
}
END_TEST

START_TEST(test_s21_atan_one) {
  long double s21_atan_res = s21_atan(1);
  double atan_res = atan(1);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-6);
}
END_TEST

START_TEST(test_s21_atan_large_double) {
  long double s21_atan_res = s21_atan(53495.123);
  double atan_res = atan(53495.123);
  ck_assert_ldouble_eq_tol(s21_atan_res, atan_res, 1e-6);
}
END_TEST

Suite* create_s21_atan_suite(void) {
  Suite* s21_atan_suite;
  TCase* tc_core;

  s21_atan_suite = suite_create("s21_atan");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_atan_positive_double);
  tcase_add_test(tc_core, test_s21_atan_negative_double);
  tcase_add_test(tc_core, test_s21_atan_zero);
  tcase_add_test(tc_core, test_s21_atan_small_double);
  tcase_add_test(tc_core, test_s21_atan_one);
  tcase_add_test(tc_core, test_s21_atan_large_double);

  suite_add_tcase(s21_atan_suite, tc_core);

  return s21_atan_suite;
}

int run_s21_atan_suite() {
  int tests_number_failed = 0;

  Suite* s21_atan_suite;
  SRunner* s21_atan_suite_srunner;

  s21_atan_suite = create_s21_atan_suite();
  s21_atan_suite_srunner = srunner_create(s21_atan_suite);

  srunner_set_fork_status(s21_atan_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_atan_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_atan_suite_srunner);
  srunner_free(s21_atan_suite_srunner);

  return tests_number_failed;
}