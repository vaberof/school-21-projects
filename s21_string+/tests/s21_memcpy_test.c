#include "s21_memcpy_test.h"

#include "../s21_string.h"

START_TEST(test_s21_memcpy_copy_all_elems) {
  char src_1[24] = "source_should_be_copied";
  char dest_1[24] = "dest";
  char src_2[24] = "source_should_be_copied";
  char dest_2[24] = "dest";

  size_t n = strlen(src_1);

  ck_assert_str_eq(s21_memcpy(dest_1, src_1, n), memcpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_copy_first_n_elems) {
  char src_1[24] = "source_should_be_copied";
  char dest_1[24] = "dest";
  char src_2[24] = "source_should_be_copied";
  char dest_2[24] = "dest";

  size_t n = 3;

  ck_assert_str_eq(s21_memcpy(dest_1, src_1, n), memcpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_copy_zero_elems) {
  char src_1[24] = "source_should_be_copied";
  char dest_1[24] = "dest";
  char src_2[24] = "source_should_be_copied";
  char dest_2[24] = "dest";

  size_t n = 0;

  ck_assert_str_eq(s21_memcpy(dest_1, src_1, n), memcpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_copy_empty_string) {
  char src_1[10] = "";
  char dest_1[24] = "dest";
  char src_2[10] = "";
  char dest_2[24] = "dest";

  size_t n = 15;

  ck_assert_str_eq(s21_memcpy(dest_1, src_1, n), memcpy(dest_2, src_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_copy_to_empty_string) {
  char src_1[10] = "source";
  char dest_1[24] = "";
  char src_2[10] = "source";
  char dest_2[24] = "";

  size_t n = 15;

  ck_assert_str_eq(s21_memcpy(dest_1, src_1, n), memcpy(dest_2, src_2, n));
}
END_TEST

Suite *create_s21_memcpy_suite(void) {
  Suite *s21_memcpy_suite;
  TCase *tc_core;

  s21_memcpy_suite = suite_create("s21_memcpy");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_memcpy_copy_all_elems);
  tcase_add_test(tc_core, test_s21_memcpy_copy_first_n_elems);
  tcase_add_test(tc_core, test_s21_memcpy_copy_zero_elems);
  tcase_add_test(tc_core, test_s21_memcpy_copy_empty_string);
  tcase_add_test(tc_core, test_s21_memcpy_copy_to_empty_string);

  suite_add_tcase(s21_memcpy_suite, tc_core);

  return s21_memcpy_suite;
}

int run_s21_memcpy_suite() {
  int tests_number_failed = 0;

  Suite *s21_memcpy_suite;
  SRunner *s21_memcpy_suite_srunner;

  s21_memcpy_suite = create_s21_memcpy_suite();
  s21_memcpy_suite_srunner = srunner_create(s21_memcpy_suite);

  srunner_set_fork_status(s21_memcpy_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_memcpy_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_memcpy_suite_srunner);
  srunner_free(s21_memcpy_suite_srunner);

  return tests_number_failed;
}