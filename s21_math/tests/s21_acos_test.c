#include "s21_acos_test.h"

START_TEST(test_s21_acos_positive_double) {
  long double s21_acos_res = s21_acos(0.583053);
  double acos_res = acos(0.583053);
  ck_assert_ldouble_eq_tol(s21_acos_res, acos_res, 1e-6);
}
END_TEST

START_TEST(test_s21_acos_negative_double) {
  long double s21_acos_res = s21_acos(-3456.932);
  double acos_res = acos(-3456.932);
  ck_assert_double_nan(s21_acos_res);
  ck_assert_double_nan(acos_res);
}
END_TEST

START_TEST(test_s21_acos_negative_one) {
  long double s21_acos_res = s21_acos(-1);
  double acos_res = acos(-1);
  ck_assert_ldouble_eq_tol(s21_acos_res, acos_res, 1e-6);
}
END_TEST

START_TEST(test_s21_acos_positive_one) {
  long double s21_acos_res = s21_acos(1);
  double acos_res = acos(1);
  ck_assert_ldouble_eq_tol(s21_acos_res, acos_res, 1e-6);
}
END_TEST

START_TEST(test_s21_acos_zero) {
  long double s21_acos_res = s21_acos(0);
  double acos_res = acos(0);
  ck_assert_ldouble_eq_tol(s21_acos_res, acos_res, 1e-6);
}
END_TEST

Suite* create_s21_acos_suite(void) {
  Suite* s21_acos_suite;
  TCase* tc_core;

  s21_acos_suite = suite_create("s21_acos");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_acos_positive_double);
  tcase_add_test(tc_core, test_s21_acos_negative_double);
  tcase_add_test(tc_core, test_s21_acos_positive_one);
  tcase_add_test(tc_core, test_s21_acos_negative_one);
  tcase_add_test(tc_core, test_s21_acos_zero);

  suite_add_tcase(s21_acos_suite, tc_core);

  return s21_acos_suite;
}

int run_s21_acos_suite() {
  int tests_number_failed = 0;

  Suite* s21_acos_suite;
  SRunner* s21_acos_suite_srunner;

  s21_acos_suite = create_s21_acos_suite();
  s21_acos_suite_srunner = srunner_create(s21_acos_suite);

  srunner_set_fork_status(s21_acos_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_acos_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_acos_suite_srunner);
  srunner_free(s21_acos_suite_srunner);

  return tests_number_failed;
}