#include "s21_strerror_test.h"

#include <stdio.h>

#include "../s21_string.h"

START_TEST(test_s21_strerror) {
  for (int i = -300; i < 300; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *create_s21_strerror_suite(void) {
  Suite *s21_strerror_suite;
  TCase *tc_core;

  s21_strerror_suite = suite_create("s21_strerror");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strerror);

  suite_add_tcase(s21_strerror_suite, tc_core);

  return s21_strerror_suite;
}

int run_s21_strerror_suite() {
  int tests_number_failed = 0;

  Suite *s21_strerror_suite;
  SRunner *s21_strerror_suite_srunner;

  s21_strerror_suite = create_s21_strerror_suite();
  s21_strerror_suite_srunner = srunner_create(s21_strerror_suite);

  srunner_set_fork_status(s21_strerror_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strerror_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_strerror_suite_srunner);
  srunner_free(s21_strerror_suite_srunner);

  return tests_number_failed;
}