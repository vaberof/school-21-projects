#include "s21_tan_test.h"

// START_TEST(test_s21_tan_with_zero) {
//   long double math_tan = tan(0.0);
//   long double my_tan = s21_tan(0.0);
//   ck_assert_double_eq(math_tan, my_tan);
// }
// END_TEST
//
// START_TEST(test_s21_tan_NAN) {
//   long double math_tan = tan(NAN);
//   long double my_tan = s21_tan(NAN);
//   ck_assert_double_nan(math_tan);
//   ck_assert_double_nan(my_tan);
// }
// END_TEST
//
// START_TEST(test_s21_tan_NAN_2) {
//   long double math_tan = tan(-1);
//   long double my_tan = s21_tan(-1);
//   ck_assert_double_nan(math_tan);
//   ck_assert_double_nan(my_tan);
// }
// END_TEST
//
// START_TEST(test_s21_tan_inf) {
//   long double math_tan = tan(inf);
//   long double my_tan = s21_tan(inf);
//   ck_assert_double_eq(math_tan, my_tan);
// }
// END_TEST

START_TEST(test_s21_tan) {
  long double math_tan = 0.0;
  long double my_tan = 0.0;
  for (float i = 2; i < 15; i += 0.01) {
    // printf("%.10f\n", i);

    math_tan = tan(i);
    my_tan = s21_tan(i);
    //    long double increase = math_tan * 1e6;
    //    math_tan = roundl(increase);
    //    math_tan /= 1e6;
    //    increase = my_tan * 1e6;
    //    my_tan = roundl(increase);
    //    my_tan /= 1e6;
    //    printf("%.17Le\n", math_tan);
    //    printf("%.17Le\n", my_tan);

    ck_assert_double_eq_tol(math_tan, my_tan, 1e-6);
  }
}
END_TEST

Suite* create_s21_tan_suite(void) {
  Suite* s21_tan_suite;
  TCase* tc_core;

  s21_tan_suite = suite_create("s21_tan");
  tc_core = tcase_create("core");

  //  tcase_add_test(tc_core, test_s21_tan_with_zero);
  //  tcase_add_test(tc_core, test_s21_tan_NAN);
  //  tcase_add_test(tc_core, test_s21_tan_NAN_2);
  //  tcase_add_test(tc_core, test_s21_tan_inf);

  tcase_add_test(tc_core, test_s21_tan);

  suite_add_tcase(s21_tan_suite, tc_core);

  return s21_tan_suite;
}

int run_s21_tan_suite() {
  int tests_number_failed = 0;

  Suite* s21_tan_suite;
  SRunner* s21_tan_suite_srunner;

  s21_tan_suite = create_s21_tan_suite();
  s21_tan_suite_srunner = srunner_create(s21_tan_suite);

  srunner_set_fork_status(s21_tan_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_tan_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_tan_suite_srunner);
  srunner_free(s21_tan_suite_srunner);

  return tests_number_failed;
}