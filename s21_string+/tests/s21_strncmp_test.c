#include "s21_strncmp_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strncmp_first_string_has_more_length) {
  char *str1 = "hello_world";
  char *str2 = "hello_worl";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_second_string_has_more_length) {
  char *str1 = "hello_worl";
  char *str2 = "hello_world";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_first_string_is_empty) {
  char *str1 = "";
  char *str2 = "hello_world";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_second_string_is_empty) {
  char *str1 = "hello_worl";
  char *str2 = "";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_same_strings) {
  char *str1 = "hello_world";
  char *str2 = "hello_world";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_Fw) {
  char *str1 = "hello_Forld";
  char *str2 = "hello_world";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_wF) {
  char *str1 = "hello_world";
  char *str2 = "hello_Forld";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

START_TEST(test_s21_strncmp_numberF) {
  char *str1 = "hello_0orld";
  char *str2 = "hello_Forld";
  size_t str_len = strlen(str1);

  ck_assert_int_eq(s21_strncmp(str1, str2, str_len),
                   strncmp(str1, str2, str_len));
}
END_TEST

Suite *create_s21_strncmp_suite(void) {
  Suite *s21_strncmp_suite;
  TCase *tc_core;

  s21_strncmp_suite = suite_create("s21_strncmp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strncmp_same_strings);
  tcase_add_test(tc_core, test_s21_strncmp_first_string_has_more_length);
  tcase_add_test(tc_core, test_s21_strncmp_second_string_has_more_length);
  tcase_add_test(tc_core, test_s21_strncmp_first_string_is_empty);
  tcase_add_test(tc_core, test_s21_strncmp_second_string_is_empty);
  tcase_add_test(tc_core, test_s21_strncmp_Fw);
  tcase_add_test(tc_core, test_s21_strncmp_wF);
  tcase_add_test(tc_core, test_s21_strncmp_numberF);

  suite_add_tcase(s21_strncmp_suite, tc_core);

  return s21_strncmp_suite;
}

int run_s21_strncmp_suite() {
  int tests_number_failed = 0;

  Suite *s21_strncmp_suite;
  SRunner *s21_strncmp_suite_srunner;

  s21_strncmp_suite = create_s21_strncmp_suite();
  s21_strncmp_suite_srunner = srunner_create(s21_strncmp_suite);

  srunner_set_fork_status(s21_strncmp_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strncmp_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_strncmp_suite_srunner);
  srunner_free(s21_strncmp_suite_srunner);

  return tests_number_failed;
}