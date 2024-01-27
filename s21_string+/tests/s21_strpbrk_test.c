#include "s21_strpbrk_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strpbrk) {
  const char str1[20] = "source_string";
  const char str2[20] = "source_string";
  const char find_this[20] = "_";

  ck_assert_str_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_special_symbols) {
  const char str1[20] = "Hello, @world!";
  const char str2[20] = "Hello, @world!";
  const char find_this[20] = "@#!";

  ck_assert_str_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_equal_strings) {
  const char str1[20] = "abcd";
  const char str2[20] = "abcd";
  const char find_this[20] = "abcd";

  ck_assert_str_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_long_string) {
  const char str1[200] =
      "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd"
      "abcdabcdabcdabcdabcdabcd";
  const char str2[200] =
      "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd"
      "abcdabcdabcdabcdabcdabcd";
  const char find_this[20] = "c";

  ck_assert_str_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_no_matches) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  const char find_this[20] = "fk";

  ck_assert_ptr_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_find_empty) {
  const char str1[20] = "Hello, world!";
  const char str2[20] = "Hello, world!";
  const char find_this[20] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_find_in_empty) {
  const char str1[20] = "";
  const char str2[20] = "";
  const char find_this[20] = "h";

  ck_assert_ptr_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

START_TEST(test_s21_strpbrk_find_empty_in_empty) {
  const char str1[20] = "";
  const char str2[20] = "";
  const char find_this[20] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, find_this), strpbrk(str2, find_this));
}
END_TEST

Suite *create_s21_strpbrk_suite(void) {
  Suite *s21_strpbrk_suite;
  TCase *tc_core;

  s21_strpbrk_suite = suite_create("s21_strpbrk");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strpbrk_special_symbols);
  tcase_add_test(tc_core, test_s21_strpbrk_equal_strings);
  tcase_add_test(tc_core, test_s21_strpbrk_long_string);
  tcase_add_test(tc_core, test_s21_strpbrk_no_matches);
  tcase_add_test(tc_core, test_s21_strpbrk_find_empty);
  tcase_add_test(tc_core, test_s21_strpbrk_find_in_empty);
  tcase_add_test(tc_core, test_s21_strpbrk_find_empty_in_empty);

  suite_add_tcase(s21_strpbrk_suite, tc_core);

  return s21_strpbrk_suite;
}

int run_s21_strpbrk_suite() {
  int tests_number_failed = 0;

  Suite *s21_strpbrk_suite;
  SRunner *s21_strpbrk_suite_srunner;

  s21_strpbrk_suite = create_s21_strpbrk_suite();
  s21_strpbrk_suite_srunner = srunner_create(s21_strpbrk_suite);

  srunner_set_fork_status(s21_strpbrk_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strpbrk_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strpbrk_suite_srunner);
  srunner_free(s21_strpbrk_suite_srunner);

  return tests_number_failed;
}