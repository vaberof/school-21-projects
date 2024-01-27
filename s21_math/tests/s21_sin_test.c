#include "s21_sin_test.h"

START_TEST(test_s21_sin_with_zero) {
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 0.000001);
  ck_assert_double_eq_tol(s21_sin(6.12), sin(6.12), 0.000001);
  ck_assert_double_eq_tol(s21_sin(-12.6), sin(-12.6), 0.000001);
  ck_assert_double_nan(s21_sin(NaN));
  ck_assert_ldouble_nan(s21_sin(inf));
  ck_assert_double_nan(s21_sin(inf));

  long double math_sin = sin(0.0);
  long double my_sin = s21_sin(0.0);
  ck_assert_double_eq(math_sin, my_sin);
}
END_TEST

START_TEST(test_s21_sin_NAN) {
  long double math_sin = sin(NAN);
  long double my_sin = s21_sin(NAN);
  ck_assert_double_nan(math_sin);
  ck_assert_double_nan(my_sin);
}
END_TEST

START_TEST(test_s21_sin_left_border) {
  long double math_sin = sin(-1);
  long double my_sin = s21_sin(-1);
  ck_assert_double_eq(math_sin, my_sin);
}
END_TEST

START_TEST(test_s21_sin_right_border) {
  long double math_sin = sin(1);
  long double my_sin = s21_sin(1);
  ck_assert_double_eq(math_sin, my_sin);
}
END_TEST

START_TEST(test_s21_sin_inf) {
  long double math_sin = sin(inf);
  long double my_sin = s21_sin(inf);
  ck_assert_double_nan(math_sin);
  ck_assert_double_nan(my_sin);
}
END_TEST

START_TEST(test_s21_sin) {
  long double math_sin = 0.0;
  long double my_sin = 0.0;
  for (float i = 0.000; i < 15; i += 0.01) {
    // printf("%.10f\n", i);

    math_sin = sin(i);
    my_sin = s21_sin(i);

    ck_assert_double_eq_tol(math_sin, my_sin, 1e-6);
  }
}
END_TEST

Suite* create_s21_sin_suite(void) {
  Suite* s21_sin_suite;
  TCase* tc_core;

  s21_sin_suite = suite_create("s21_sin");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_sin_with_zero);
  tcase_add_test(tc_core, test_s21_sin_NAN);
  tcase_add_test(tc_core, test_s21_sin_left_border);
  tcase_add_test(tc_core, test_s21_sin_right_border);
  tcase_add_test(tc_core, test_s21_sin_inf);

  tcase_add_test(tc_core, test_s21_sin);

  suite_add_tcase(s21_sin_suite, tc_core);

  return s21_sin_suite;
}

int run_s21_sin_suite() {
  int tests_number_failed = 0;

  Suite* s21_sin_suite;
  SRunner* s21_sin_suite_srunner;

  s21_sin_suite = create_s21_sin_suite();
  s21_sin_suite_srunner = srunner_create(s21_sin_suite);

  srunner_set_fork_status(s21_sin_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_sin_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_sin_suite_srunner);
  srunner_free(s21_sin_suite_srunner);

  return tests_number_failed;
}