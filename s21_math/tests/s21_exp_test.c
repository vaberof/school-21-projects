#include "s21_exp_test.h"

START_TEST(test_s21_exp) {
  long double math_exp = 0.0;
  long double my_exp = 0.0;

  for (float i = 0.0; i < 40; i += 0.1) {
    math_exp = expl(i);
    my_exp = s21_exp(i);
    ck_assert_double_eq_tol(math_exp, my_exp, 1e-6);
  }
}
END_TEST

Suite* create_s21_exp_suite(void) {
  Suite* s21_exp_suite;
  TCase* tc_core;

  s21_exp_suite = suite_create("s21_exp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_exp);

  suite_add_tcase(s21_exp_suite, tc_core);

  return s21_exp_suite;
}

int run_s21_exp_suite() {
  int tests_number_failed = 0;

  Suite* s21_exp_suite;
  SRunner* s21_exp_suite_srunner;

  s21_exp_suite = create_s21_exp_suite();
  s21_exp_suite_srunner = srunner_create(s21_exp_suite);

  srunner_set_fork_status(s21_exp_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_exp_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_exp_suite_srunner);
  srunner_free(s21_exp_suite_srunner);

  return tests_number_failed;
}