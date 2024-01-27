#include "s21_strcspn_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strcspn_search_existing_character) {
  const char *str = "hello_world";
  const char *matching_characters = "world";

  ck_assert_uint_eq(s21_strcspn(str, matching_characters),
                    strcspn(str, matching_characters));
}
END_TEST

START_TEST(test_s21_strcspn_search_nonexisting_character) {
  char *str = "find_non_existing_character";
  const char *matching_characters = "w";

  ck_assert_uint_eq(s21_strcspn(str, matching_characters),
                    strcspn(str, matching_characters));
}
END_TEST

START_TEST(test_s21_strcspn_search_nonexisting_character_in_empty_string) {
  char *str = "";
  const char *matching_character = "world";

  ck_assert_uint_eq(s21_strcspn(str, matching_character),
                    strcspn(str, matching_character));
}
END_TEST

START_TEST(test_s21_strcspn_search_empty_character_in_string) {
  char *str = "find";
  const char *matching_character = "";

  ck_assert_uint_eq(s21_strcspn(str, matching_character),
                    strcspn(str, matching_character));
}
END_TEST

Suite *create_s21_strcspn_suite(void) {
  Suite *s21_strcspn_suite;
  TCase *tc_core;

  s21_strcspn_suite = suite_create("s21_strcspn");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strcspn_search_existing_character);
  tcase_add_test(tc_core, test_s21_strcspn_search_nonexisting_character);
  tcase_add_test(tc_core,
                 test_s21_strcspn_search_nonexisting_character_in_empty_string);
  tcase_add_test(tc_core, test_s21_strcspn_search_empty_character_in_string);

  suite_add_tcase(s21_strcspn_suite, tc_core);

  return s21_strcspn_suite;
}

int run_s21_strcspn_suite() {
  int tests_number_failed = 0;

  Suite *s21_strcspn_suite;
  SRunner *s21_strcspn_suite_srunner;

  s21_strcspn_suite = create_s21_strcspn_suite();
  s21_strcspn_suite_srunner = srunner_create(s21_strcspn_suite);

  srunner_set_fork_status(s21_strcspn_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strcspn_suite_srunner, CK_VERBOSE);

  tests_number_failed = srunner_ntests_failed(s21_strcspn_suite_srunner);
  srunner_free(s21_strcspn_suite_srunner);

  return tests_number_failed;
}