#include "s21_math_test.h"

int main() {
  int tests_number_failed = 0;

  tests_number_failed += run_s21_log_suite();
  tests_number_failed += run_s21_exp_suite();
  tests_number_failed += run_s21_pow_suite();
  tests_number_failed += run_s21_sqrt_suite();
  tests_number_failed += run_s21_sin_suite();
  tests_number_failed += run_s21_cos_suite();
  tests_number_failed += run_s21_floor_suite();
  tests_number_failed += run_s21_fmod_suite();
  tests_number_failed += run_s21_ceil_suite();
  tests_number_failed += run_s21_fabs_suite();
  tests_number_failed += run_s21_abs_suite();
  tests_number_failed += run_s21_acos_suite();
  tests_number_failed += run_s21_asin_suite();
  tests_number_failed += run_s21_atan_suite();
  tests_number_failed += run_s21_tan_suite();

  return (tests_number_failed == 0) ? 0 : 1;
}
