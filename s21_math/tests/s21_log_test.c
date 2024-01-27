#include "s21_log_test.h"

START_TEST(test_s21_log_with_zero) {
  long double math_log = log(0);
  long double my_log = s21_log(0);
  ck_assert_double_eq(math_log, my_log);
}
END_TEST

START_TEST(test_s21_log_NAN) {
  long double math_log = log(NAN);
  long double my_log = s21_log(NAN);
  ck_assert_double_nan(math_log);
  ck_assert_double_nan(my_log);
}
END_TEST

START_TEST(test_s21_log_inf) {
  long double math_log = log(inf);
  long double my_log = s21_log(inf);
  ck_assert_double_eq(math_log, my_log);
}
END_TEST

START_TEST(test_s21_log_negative) {
  long double math_log = log(-1);
  long double my_log = s21_log(-1);
  ck_assert_double_nan(math_log);
  ck_assert_double_nan(my_log);
}
END_TEST

START_TEST(test_s21_log_one) {
  long double math_log = log(1);
  long double my_log = s21_log(1);
  ck_assert_double_eq(math_log, my_log);
}
END_TEST

START_TEST(test_s21_log) {
  long double math_log = 0.0;
  long double my_log = 0.0;
  for (float i = 0.01; i < 100; i += 0.01) {
    // printf("%.10f\n", i);

    math_log = logl(i);
    my_log = s21_log(i);
    //    long double increase = math_log * 1e10;
    //    math_log = roundl(increase);
    //    math_log /= 1e10;
    //    increase = my_log * 1e10;
    //    my_log = roundl(increase);
    //    my_log /= 1e10;
    //    printf("%.17Le\n", math_log);
    //    printf("%.17Le\n", my_log);

    ck_assert_double_eq_tol(math_log, my_log, 1e-6);
  }
}
END_TEST

Suite* create_s21_log_suite(void) {
  Suite* s21_log_suite;
  TCase* tc_core;

  s21_log_suite = suite_create("s21_log");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_log_with_zero);
  tcase_add_test(tc_core, test_s21_log_NAN);
  tcase_add_test(tc_core, test_s21_log_inf);
  tcase_add_test(tc_core, test_s21_log_negative);
  tcase_add_test(tc_core, test_s21_log_one);
  tcase_add_test(tc_core, test_s21_log);

  suite_add_tcase(s21_log_suite, tc_core);

  return s21_log_suite;
}

int run_s21_log_suite() {
  int tests_number_failed = 0;

  Suite* s21_log_suite;
  SRunner* s21_log_suite_srunner;

  s21_log_suite = create_s21_log_suite();
  s21_log_suite_srunner = srunner_create(s21_log_suite);

  srunner_set_fork_status(s21_log_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_log_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_log_suite_srunner);
  srunner_free(s21_log_suite_srunner);

  return tests_number_failed;
}