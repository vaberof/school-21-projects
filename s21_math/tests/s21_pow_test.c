#include "s21_pow_test.h"

START_TEST(test_s21_pow_with_zero) {
  long double math_pow = pow(0.0, 0.0);
  long double my_pow = s21_pow(0.0, 0.0);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

START_TEST(test_s21_pow_with_zero_2) {
  long double math_pow = pow(inf, -1);
  long double my_pow = s21_pow(inf, -1);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

START_TEST(test_s21_pow_with_zero_3) {
  long double math_pow = pow(0.0, 1);
  long double my_pow = s21_pow(0.0, 1);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

START_TEST(test_s21_pow_NAN) {
  long double math_pow = pow(NAN, NAN);
  long double my_pow = s21_pow(NAN, NAN);
  ck_assert_double_nan(math_pow);
  ck_assert_double_nan(my_pow);
}
END_TEST

START_TEST(test_s21_pow_NAN_2) {
  long double math_pow = pow(-1, inf);
  long double my_pow = s21_pow(-1, inf);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

START_TEST(test_s21_pow_inf) {
  long double math_pow = pow(inf, 1);
  long double my_pow = s21_pow(inf, 1);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

START_TEST(test_s21_pow_inf_2) {
  long double math_pow = pow(0.0, -1);
  long double my_pow = s21_pow(0.0, -1);
  ck_assert_double_eq(math_pow, my_pow);
}
END_TEST

Suite* create_s21_pow_suite(void) {
  Suite* s21_pow_suite;
  TCase* tc_core;

  s21_pow_suite = suite_create("s21_pow");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_pow_with_zero);
  tcase_add_test(tc_core, test_s21_pow_with_zero_2);
  tcase_add_test(tc_core, test_s21_pow_with_zero_3);
  tcase_add_test(tc_core, test_s21_pow_NAN);
  tcase_add_test(tc_core, test_s21_pow_NAN_2);
  tcase_add_test(tc_core, test_s21_pow_inf);
  tcase_add_test(tc_core, test_s21_pow_inf_2);

  // tcase_add_test(tc_core, test_s21_pow);

  suite_add_tcase(s21_pow_suite, tc_core);

  return s21_pow_suite;
}

int run_s21_pow_suite() {
  int tests_number_failed = 0;

  Suite* s21_pow_suite;
  SRunner* s21_pow_suite_srunner;

  s21_pow_suite = create_s21_pow_suite();
  s21_pow_suite_srunner = srunner_create(s21_pow_suite);

  srunner_set_fork_status(s21_pow_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_pow_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_pow_suite_srunner);
  srunner_free(s21_pow_suite_srunner);

  return tests_number_failed;
}