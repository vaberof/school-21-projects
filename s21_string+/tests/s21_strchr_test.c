#include "s21_strchr_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strchr_search_existing_character) {
  const char *str = "hello_world";
  int matching_character = (int)'w';

  ck_assert_str_eq(s21_strchr(str, matching_character),
                   strchr(str, matching_character));
}
END_TEST

START_TEST(test_s21_strchr_search_nonexisting_character) {
  char *str = "find_non_existing_character";
  int matching_character = (int)'A';

  ck_assert_ptr_eq(s21_strchr(str, matching_character),
                   strchr(str, matching_character));
}
END_TEST

START_TEST(test_s21_strchr_search_nonexisting_character_in_empty_string) {
  char *str = "";
  int matching_character = (int)'A';

  ck_assert_ptr_eq(s21_strchr(str, matching_character),
                   strchr(str, matching_character));
}
END_TEST

Suite *create_s21_strchr_suite(void) {
  Suite *s21_strchr_suite;
  TCase *tc_core;

  s21_strchr_suite = suite_create("s21_strchr");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strchr_search_existing_character);
  tcase_add_test(tc_core, test_s21_strchr_search_nonexisting_character);
  tcase_add_test(tc_core,
                 test_s21_strchr_search_nonexisting_character_in_empty_string);

  suite_add_tcase(s21_strchr_suite, tc_core);

  return s21_strchr_suite;
}

int run_s21_strchr_suite() {
  int tests_number_failed = 0;

  Suite *s21_strchr_suite;
  SRunner *s21_strchr_suite_srunner;

  s21_strchr_suite = create_s21_strchr_suite();
  s21_strchr_suite_srunner = srunner_create(s21_strchr_suite);

  srunner_set_fork_status(s21_strchr_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strchr_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_strchr_suite_srunner);
  srunner_free(s21_strchr_suite_srunner);

  return tests_number_failed;
}