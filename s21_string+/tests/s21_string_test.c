#include "s21_string_test.h"

int main() {
  int tests_number_failed = 0;

  tests_number_failed += run_s21_memchr_suite();
  tests_number_failed += run_s21_memcmp_suite();
  tests_number_failed += run_s21_memcpy_suite();
  tests_number_failed += run_s21_memset_suite();
  tests_number_failed += run_s21_strncat_suite();

  tests_number_failed += run_s21_strchr_suite();
  tests_number_failed += run_s21_strncmp_suite();

  tests_number_failed += run_s21_strncpy_suite();
  tests_number_failed += run_s21_strcspn_suite();

  tests_number_failed += run_s21_to_upper_suite();
  tests_number_failed += run_s21_to_lower_suite();
  tests_number_failed += run_s21_insert_suite();
  tests_number_failed += run_s21_trim_suite();

  tests_number_failed += run_s21_strlen_suite();
  tests_number_failed += run_s21_strpbrk_suite();
  tests_number_failed += run_s21_strrchr_suite();
  tests_number_failed += run_s21_strstr_suite();
  tests_number_failed += run_s21_strtok_suite();

  tests_number_failed += run_s21_strerror_suite();

  tests_number_failed += run_s21_sprintf_suite();

  return (tests_number_failed == 0) ? 0 : 1;
}
