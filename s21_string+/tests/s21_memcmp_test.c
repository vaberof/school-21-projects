#include "s21_memcmp_test.h"

#include "../s21_string.h"

START_TEST(test_s21_memcmp_compare_same_strings) {
  char *str1 = "hello_world";
  char *str2 = "hello_world";
  size_t n = strlen(str1);

  ck_assert_uint_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_compare_diff_first_n_bytes) {
  char *str1 = "hello_world";
  char *str2 = "heoll_world";
  size_t n = 3;

  ck_assert_uint_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_compare_ints) {
  int str1 = 32145;
  int str2 = 12345;
  size_t n = 3;

  ck_assert_uint_eq(s21_memcmp(&str1, &str2, n), memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_compare_char_with_int) {
  char *str1 = "32145";
  int str2 = 12345;
  size_t n = 3;

  ck_assert_uint_eq(s21_memcmp(&str1, &str2, n), memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_compare_structs) {
  typedef struct Item {
    int a;
  } Item;

  Item item_1 = {5};
  Item item_2 = {5};

  size_t n = sizeof(item_1);

  ck_assert_uint_eq(s21_memcmp(&item_1, &item_2, n),
                    memcmp(&item_1, &item_2, n));
}
END_TEST

Suite *create_s21_memcmp_suite(void) {
  Suite *s21_memcmp_suite;
  TCase *tc_core;

  s21_memcmp_suite = suite_create("s21_memcmp");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_memcmp_compare_same_strings);
  tcase_add_test(tc_core, test_s21_memcmp_compare_diff_first_n_bytes);
  tcase_add_test(tc_core, test_s21_memcmp_compare_ints);
  tcase_add_test(tc_core, test_s21_memcmp_compare_char_with_int);
  tcase_add_test(tc_core, test_s21_memcmp_compare_structs);

  suite_add_tcase(s21_memcmp_suite, tc_core);

  return s21_memcmp_suite;
}

int run_s21_memcmp_suite() {
  int tests_number_failed = 0;

  Suite *s21_memcmp_suite;
  SRunner *s21_memcmp_suite_srunner;

  s21_memcmp_suite = create_s21_memcmp_suite();
  s21_memcmp_suite_srunner = srunner_create(s21_memcmp_suite);

  srunner_set_fork_status(s21_memcmp_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_memcmp_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_memcmp_suite_srunner);
  srunner_free(s21_memcmp_suite_srunner);

  return tests_number_failed;
}