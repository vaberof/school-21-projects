#include "s21_memchr_test.h"

#include "../s21_string.h"

START_TEST(test_s21_memchr_search_existing_character) {
  char *str = "hello_world";
  char matching_character = 'w';
  size_t n = strlen(str);

  ck_assert_str_eq(s21_memchr(str, matching_character, n),
                   memchr(str, matching_character, n));
}
END_TEST

START_TEST(test_s21_memchr_search_nonexisting_character) {
  char *str = "find_non_existing_character";
  char matching_character = 'A';
  size_t n = strlen(str);

  ck_assert_ptr_eq(s21_memchr(str, matching_character, n),
                   memchr(str, matching_character, n));
}
END_TEST

START_TEST(test_s21_memchr_search_character_in_empty_string) {
  char *str = "";
  char matching_character = 'A';
  size_t n = strlen(str);

  ck_assert_ptr_eq(s21_memchr(str, matching_character, n),
                   memchr(str, matching_character, n));
}
END_TEST

START_TEST(test_s21_memchr_search_existing_character_in_first_n_bytes) {
  char *str = "test_string";
  char matching_character = 's';
  size_t n = 4;

  ck_assert_ptr_eq(s21_memchr(str, matching_character, n),
                   memchr(str, matching_character, n));
}
END_TEST

START_TEST(test_s21_memchr_search_nonexisting_character_in_first_n_bytes) {
  char *str = "test_string";
  char matching_character = 'A';
  size_t n = 4;

  ck_assert_ptr_eq(s21_memchr(str, matching_character, n),
                   memchr(str, matching_character, n));
}
END_TEST

Suite *create_s21_memchr_suite(void) {
  Suite *s21_memchr_suite;
  TCase *tc_core;

  s21_memchr_suite = suite_create("s21_memchr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_memchr_search_existing_character);
  tcase_add_test(tc_core, test_s21_memchr_search_nonexisting_character);
  tcase_add_test(tc_core, test_s21_memchr_search_character_in_empty_string);
  tcase_add_test(tc_core,
                 test_s21_memchr_search_existing_character_in_first_n_bytes);
  tcase_add_test(tc_core,
                 test_s21_memchr_search_nonexisting_character_in_first_n_bytes);

  suite_add_tcase(s21_memchr_suite, tc_core);

  return s21_memchr_suite;
}

int run_s21_memchr_suite() {
  int tests_number_failed = 0;

  Suite *s21_memchr_suite;
  SRunner *s21_memchr_suite_srunner;

  s21_memchr_suite = create_s21_memchr_suite();

  s21_memchr_suite_srunner = srunner_create(s21_memchr_suite);

  srunner_set_fork_status(s21_memchr_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_memchr_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_memchr_suite_srunner);
  srunner_free(s21_memchr_suite_srunner);
  return tests_number_failed;
}