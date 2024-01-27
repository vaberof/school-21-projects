#include "s21_cos_test.h"

START_TEST(test_s21_cos_positive_1) {
  long double s21_cos_ret = s21_cos(180.0);
  long double cos_ret = cos(180.0);
  ck_assert_ldouble_eq_tol(s21_cos_ret, cos_ret, 1e-6);
}
END_TEST

START_TEST(test_s21_cos_zero) {
  long double s21_cos_ret = s21_cos(0.0);
  long double cos_ret = cos(0.0);
  ck_assert_ldouble_eq_tol(s21_cos_ret, cos_ret, 1e-6);
}
END_TEST

START_TEST(test_s21_cos_negative_1) {
  long double s21_cos_ret = s21_cos(-180.0);
  long double cos_ret = cos(-180.0);
  ck_assert_ldouble_eq_tol(s21_cos_ret, cos_ret, 1e-6);
}
END_TEST

START_TEST(test_s21_cos_nan) {
  long double s21_cos_ret = s21_cos(NaN);
  long double cos_ret = cos(NaN);
  ck_assert_ldouble_nan(s21_cos_ret);
  ck_assert_ldouble_nan(cos_ret);
}
END_TEST

Suite* create_s21_cos_suite(void) {
  Suite* s21_cos_suite;
  TCase* tc_core;

  s21_cos_suite = suite_create("s21_cos");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_cos_positive_1);
  tcase_add_test(tc_core, test_s21_cos_zero);
  tcase_add_test(tc_core, test_s21_cos_negative_1);
  tcase_add_test(tc_core, test_s21_cos_nan);

  suite_add_tcase(s21_cos_suite, tc_core);

  return s21_cos_suite;
}

int run_s21_cos_suite() {
  int tests_number_failed = 0;

  Suite* s21_cos_suite;
  SRunner* s21_cos_suite_srunner;

  s21_cos_suite = create_s21_cos_suite();
  s21_cos_suite_srunner = srunner_create(s21_cos_suite);

  srunner_set_fork_status(s21_cos_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_cos_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_cos_suite_srunner);
  srunner_free(s21_cos_suite_srunner);

  return tests_number_failed;
}