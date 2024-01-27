#include "s21_ceil_test.h"

START_TEST(test_s21_ceil) {
  ck_assert_ldouble_eq(s21_ceil(1.2), ceil(1.2));
  ck_assert_ldouble_eq(s21_ceil(5.7), ceil(5.7));
  ck_assert_ldouble_eq(s21_ceil(-1.2), ceil(-1.2));
  ck_assert_ldouble_eq(s21_ceil(-5.7), ceil(-5.7));

  ck_assert_ldouble_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_ldouble_eq(s21_ceil(0.12356789), ceil(0.123456789));
  ck_assert_ldouble_eq(s21_ceil(0.00), ceil(0.00));
  ck_assert_ldouble_eq(s21_ceil(-1234567890.12345), ceil(-1234567890.12345));
  ck_assert_ldouble_eq(s21_ceil(2121.2121), ceil(2121.2121));
  ck_assert_ldouble_eq(s21_ceil(-987.789), ceil(-987.789));
  ck_assert_ldouble_eq(s21_ceil(-0.00), ceil(-0.00));
  ck_assert_ldouble_eq(s21_ceil(0.499999999), ceil(0.499999999));
  ck_assert_ldouble_eq(s21_ceil(210), ceil(210));
}
END_TEST

Suite* create_s21_ceil_suite(void) {
  Suite* s21_ceil_suite;
  TCase* tc_core;

  s21_ceil_suite = suite_create("s21_ceil");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_ceil);

  suite_add_tcase(s21_ceil_suite, tc_core);

  return s21_ceil_suite;
}

int run_s21_ceil_suite() {
  int tests_number_failed = 0;

  Suite* s21_ceil_suite;
  SRunner* s21_ceil_suite_srunner;

  s21_ceil_suite = create_s21_ceil_suite();
  s21_ceil_suite_srunner = srunner_create(s21_ceil_suite);

  srunner_set_fork_status(s21_ceil_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_ceil_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_ceil_suite_srunner);
  srunner_free(s21_ceil_suite_srunner);

  return tests_number_failed;
}