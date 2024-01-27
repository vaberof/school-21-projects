#include "s21_sqrt_test.h"

START_TEST(test_s21_sqrt_with_zero) {
  long double math_sqrt = sqrt(0.0);
  long double my_sqrt = s21_sqrt(0.0);
  ck_assert_double_eq(math_sqrt, my_sqrt);
}
END_TEST

START_TEST(test_s21_sqrt_NAN) {
  long double math_sqrt = sqrt(NAN);
  long double my_sqrt = s21_sqrt(NAN);
  ck_assert_double_nan(math_sqrt);
  ck_assert_double_nan(my_sqrt);
}
END_TEST

START_TEST(test_s21_sqrt_NAN_2) {
  long double math_sqrt = sqrt(-1);
  long double my_sqrt = s21_sqrt(-1);
  ck_assert_double_nan(math_sqrt);
  ck_assert_double_nan(my_sqrt);
}
END_TEST

START_TEST(test_s21_sqrt_inf) {
  long double math_sqrt = sqrt(inf);
  long double my_sqrt = s21_sqrt(inf);
  ck_assert_double_eq(math_sqrt, my_sqrt);
}
END_TEST

START_TEST(test_s21_sqrt) {
  long double math_sqrt = 0.0;
  long double my_sqrt = 0.0;
  for (float i = 2; i < 15; i += 0.01) {
    // printf("%.10f\n", i);

    math_sqrt = sqrt(i);
    my_sqrt = s21_sqrt(i);
    //    long double increase = math_sqrt * 1e6;
    //    math_sqrt = roundl(increase);
    //    math_sqrt /= 1e6;
    //    increase = my_sqrt * 1e6;
    //    my_sqrt = roundl(increase);
    //    my_sqrt /= 1e6;
    //    printf("%.17Le\n", math_sqrt);
    //    printf("%.17Le\n", my_sqrt);

    ck_assert_double_eq_tol(math_sqrt, my_sqrt, 1e-6);
  }
}
END_TEST

Suite* create_s21_sqrt_suite(void) {
  Suite* s21_sqrt_suite;
  TCase* tc_core;

  s21_sqrt_suite = suite_create("s21_sqrt");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_sqrt_with_zero);
  tcase_add_test(tc_core, test_s21_sqrt_NAN);
  tcase_add_test(tc_core, test_s21_sqrt_NAN_2);
  tcase_add_test(tc_core, test_s21_sqrt_inf);

  tcase_add_test(tc_core, test_s21_sqrt);

  suite_add_tcase(s21_sqrt_suite, tc_core);

  return s21_sqrt_suite;
}

int run_s21_sqrt_suite() {
  int tests_number_failed = 0;

  Suite* s21_sqrt_suite;
  SRunner* s21_sqrt_suite_srunner;

  s21_sqrt_suite = create_s21_sqrt_suite();
  s21_sqrt_suite_srunner = srunner_create(s21_sqrt_suite);

  srunner_set_fork_status(s21_sqrt_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_sqrt_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_sqrt_suite_srunner);
  srunner_free(s21_sqrt_suite_srunner);

  return tests_number_failed;
}