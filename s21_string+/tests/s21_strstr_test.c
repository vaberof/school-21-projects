#include "s21_strstr_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strstr) {
  const char haystack1[20] = "Hello, world!";
  const char haystack2[20] = "Hello, world!";
  const char needle[20] = "world";

  ck_assert_str_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_full_equal) {
  const char haystack1[20] = "Hello, world!";
  const char haystack2[20] = "Hello, world!";
  const char needle[20] = "Hello, world!";

  ck_assert_str_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_no_matches) {
  const char haystack1[20] = "Hello, world!";
  const char haystack2[20] = "Hello, world!";
  const char needle[20] = "foo";

  ck_assert_ptr_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_empty) {
  const char haystack1[20] = "";
  const char haystack2[20] = "";
  const char needle[20] = "";

  ck_assert_str_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_one_character) {
  const char haystack1[20] = "Hello, world!";
  const char haystack2[20] = "Hello, world!";
  const char needle[20] = "o";

  ck_assert_str_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_empty_haystack) {
  const char haystack1[20] = "";
  const char haystack2[20] = "";
  const char needle[20] = "o";

  ck_assert_ptr_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
  const char haystack1[20] = "World!";
  const char haystack2[20] = "World!";
  const char needle[20] = "";

  ck_assert_str_eq(s21_strstr(haystack1, needle), strstr(haystack2, needle));
}
END_TEST

Suite *create_s21_strstr_suite(void) {
  Suite *s21_strstr_suite;
  TCase *tc_core;

  s21_strstr_suite = suite_create("s21_strstr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strstr_full_equal);
  tcase_add_test(tc_core, test_s21_strstr_no_matches);
  tcase_add_test(tc_core, test_s21_strstr_empty);
  tcase_add_test(tc_core, test_s21_strstr_one_character);
  tcase_add_test(tc_core, test_s21_strstr_empty_haystack);
  tcase_add_test(tc_core, test_s21_strstr_empty_needle);

  suite_add_tcase(s21_strstr_suite, tc_core);

  return s21_strstr_suite;
}

int run_s21_strstr_suite() {
  int tests_number_failed = 0;

  Suite *s21_strstr_suite;
  SRunner *s21_strstr_suite_srunner;

  s21_strstr_suite = create_s21_strstr_suite();
  s21_strstr_suite_srunner = srunner_create(s21_strstr_suite);

  srunner_set_fork_status(s21_strstr_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strstr_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strstr_suite_srunner);
  srunner_free(s21_strstr_suite_srunner);

  return tests_number_failed;
}