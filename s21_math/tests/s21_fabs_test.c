#include "s21_fabs_test.h"

START_TEST(test_s21_fabs) {
  ck_assert_double_eq(s21_fabs(-1.123), fabs(1.123));
  ck_assert_double_eq(s21_fabs(1.123), fabs(-1.123));
  ck_assert_double_eq(s21_fabs(0.00), fabs(0.00));
  ck_assert_double_eq(s21_fabs(-1234567890.1234567890),
                      fabs(1234567890.1234567890));
  ck_assert_double_eq(s21_fabs(2121.2121), fabs(2121.2121));
  ck_assert_double_eq(s21_fabs(-987.789), fabs(-987.789));
}
END_TEST

Suite* create_s21_fabs_suite(void) {
  Suite* s21_fabs_suite;
  TCase* tc_core;

  s21_fabs_suite = suite_create("s21_fabs");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_fabs);

  suite_add_tcase(s21_fabs_suite, tc_core);

  return s21_fabs_suite;
}

int run_s21_fabs_suite() {
  int tests_number_failed = 0;

  Suite* s21_fabs_suite;
  SRunner* s21_fabs_suite_srunner;

  s21_fabs_suite = create_s21_fabs_suite();
  s21_fabs_suite_srunner = srunner_create(s21_fabs_suite);

  srunner_set_fork_status(s21_fabs_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_fabs_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_fabs_suite_srunner);
  srunner_free(s21_fabs_suite_srunner);

  return tests_number_failed;
}