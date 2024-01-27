#include "s21_fmod_test.h"

START_TEST(test_s21_fmod) {
  long double s21_fmod_ret = s21_fmod(7.3, 2.9);
  long double fmod_ret = fmod(7.3, 2.9);
  ck_assert_ldouble_eq(s21_fmod_ret, fmod_ret);
}
END_TEST

START_TEST(test_s21_fmod_negative_divider) {
  long double s21_fmod_ret = s21_fmod(7.3, -5);
  long double fmod_ret = fmod(7.3, -5);
  ck_assert_ldouble_eq(s21_fmod_ret, fmod_ret);
}
END_TEST

START_TEST(test_s21_fmod_negative_args) {
  long double s21_fmod_ret = s21_fmod(-7.3, -5);
  long double fmod_ret = fmod(-7.3, -5);
  ck_assert_ldouble_eq(s21_fmod_ret, fmod_ret);
}
END_TEST

START_TEST(test_s21_fmod_nan) {
  long double s21_fmod_ret = s21_fmod(7.3, 0);
  long double fmod_ret = fmod(7.3, 0);
  ck_assert_ldouble_nan(s21_fmod_ret);
  ck_assert_ldouble_nan(fmod_ret);
}
END_TEST

START_TEST(test_s21_fmod_zero_args) {
  long double s21_fmod_ret = s21_fmod(0, 0);
  long double fmod_ret = fmod(0, 0);
  ck_assert_ldouble_nan(s21_fmod_ret);
  ck_assert_ldouble_nan(fmod_ret);
}
END_TEST

Suite* create_s21_fmod_suite(void) {
  Suite* s21_fmod_suite;
  TCase* tc_core;

  s21_fmod_suite = suite_create("s21_fmod");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_fmod);
  tcase_add_test(tc_core, test_s21_fmod_negative_divider);
  tcase_add_test(tc_core, test_s21_fmod_negative_args);
  tcase_add_test(tc_core, test_s21_fmod_zero_args);
  tcase_add_test(tc_core, test_s21_fmod_nan);

  suite_add_tcase(s21_fmod_suite, tc_core);

  return s21_fmod_suite;
}

int run_s21_fmod_suite() {
  int tests_number_failed = 0;

  Suite* s21_fmod_suite;
  SRunner* s21_fmod_suite_srunner;

  s21_fmod_suite = create_s21_fmod_suite();
  s21_fmod_suite_srunner = srunner_create(s21_fmod_suite);

  srunner_set_fork_status(s21_fmod_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_fmod_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_fmod_suite_srunner);
  srunner_free(s21_fmod_suite_srunner);

  return tests_number_failed;
}