#include "s21_strtok_test.h"

#include "../s21_string.h"

START_TEST(test_s21_strtok) {
  char str1[20] = "Geeks-for-Geeks";
  char str2[20] = "Geeks-for-Geeks";
  const char delim[20] = "-";

  char* real = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);

  while (real != NULL && expected != NULL) {
    real = s21_strtok(NULL, delim);
    expected = strtok(NULL, delim);
    if (real == NULL && expected == NULL) {
      ck_assert_ptr_eq(real, expected);
    } else {
      ck_assert_str_eq(real, expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_manual) {
  char str1[20] = "Geeks-f or-Gee ks";
  char str2[20] = "Geeks-f or-Gee ks";
  const char delim[20] = "- ";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_manual_2) {
  char str1[20] = "1/2/3/4";
  char str2[20] = "1/2/3/4";
  const char delim[20] = "/";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(test_s21_strtok_comma) {
  char str1[20] = "Hello, World!";
  char str2[20] = "Hello, World!";
  const char delim[20] = ", o";

  char* real = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);

  while (real != NULL && expected != NULL) {
    real = s21_strtok(NULL, delim);
    expected = strtok(NULL, delim);
    if (real == NULL && expected == NULL) {
      ck_assert_ptr_eq(real, expected);
    } else {
      ck_assert_str_eq(real, expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_empty_str) {
  char str1[20] = "";
  char str2[20] = "";
  const char delim[20] = ",";

  char* real = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);

  while (real != NULL && expected != NULL) {
    real = s21_strtok(NULL, delim);
    expected = strtok(NULL, delim);
    if (real == NULL && expected == NULL) {
      ck_assert_ptr_eq(real, expected);
    } else {
      ck_assert_str_eq(real, expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_empty_delim) {
  char str1[20] = "Hello";
  char str2[20] = "Hello";
  const char delim[20] = "";

  char* real = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);

  while (real != NULL && expected != NULL) {
    real = s21_strtok(NULL, delim);
    expected = strtok(NULL, delim);
    if (real == NULL && expected == NULL) {
      ck_assert_ptr_eq(real, expected);
    } else {
      ck_assert_str_eq(real, expected);
    }
  }
}
END_TEST

START_TEST(test_s21_strtok_empty_str_and_delim) {
  char str1[20] = "Hello";
  char str2[20] = "Hello";
  const char delim[20] = "";

  char* real = s21_strtok(str1, delim);
  char* expected = strtok(str2, delim);

  while (real != NULL && expected != NULL) {
    real = s21_strtok(NULL, delim);
    expected = strtok(NULL, delim);
    if (real == NULL && expected == NULL) {
      ck_assert_ptr_eq(real, expected);
    } else {
      ck_assert_str_eq(real, expected);
    }
  }
}
END_TEST

Suite* create_s21_strtok_suite(void) {
  Suite* s21_strtok_suite;
  TCase* tc_core;

  s21_strtok_suite = suite_create("s21_strtok");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_strtok_manual);
  tcase_add_test(tc_core, test_s21_strtok_manual_2);
  tcase_add_test(tc_core, test_s21_strtok_comma);
  tcase_add_test(tc_core, test_s21_strtok_empty_str);
  tcase_add_test(tc_core, test_s21_strtok_empty_delim);
  tcase_add_test(tc_core, test_s21_strtok_empty_str_and_delim);

  suite_add_tcase(s21_strtok_suite, tc_core);

  return s21_strtok_suite;
}

int run_s21_strtok_suite() {
  int tests_number_failed = 0;

  Suite* s21_strtok_suite;
  SRunner* s21_strtok_suite_srunner;

  s21_strtok_suite = create_s21_strtok_suite();
  s21_strtok_suite_srunner = srunner_create(s21_strtok_suite);

  srunner_set_fork_status(s21_strtok_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_strtok_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_strtok_suite_srunner);
  srunner_free(s21_strtok_suite_srunner);

  return tests_number_failed;
}