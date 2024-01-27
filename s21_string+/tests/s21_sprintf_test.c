#include "s21_sprintf_test.h"

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

/* TESTS CHAR SPECIFIER */
START_TEST(test_s21_sprintf_char_specifier) {
  char s21_buffer[100];
  char buffer[100];
  char c = 'a';

  s21_sprintf(s21_buffer, "%c %-c %-10c %10c", c, c, c, c);
  sprintf(buffer, "%c %-c %-10c %10c", c, c, c, c);

  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

/* TESTS INT SPECIFIER WITH POSITIVE NUMBER */
START_TEST(test_s21_sprintf_int_specifier_positive_number) {
  /* INT TEST */
  char s21_buffer_1[250];
  char buffer_1[250];
  int positive_num = 12345;

  s21_sprintf(
      s21_buffer_1,
      "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   %- d "
      "%- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
      positive_num, positive_num, positive_num, positive_num, positive_num,
      positive_num, 5, positive_num, 10, 3, positive_num, positive_num,
      positive_num, positive_num, positive_num, positive_num, positive_num,
      positive_num, positive_num, positive_num, positive_num, positive_num,
      positive_num);
  sprintf(buffer_1,
          "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   "
          "%- d %- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, 5, positive_num, 10, 3, positive_num, positive_num,
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[250];
  char buffer_2[250];
  short int short_positive_num = 123;

  s21_sprintf(s21_buffer_2,
              "%hd %5hd %10.3hd %7.0hd %3.hd   %-hd %-*hd %-*.*hd   %-+hd "
              "%-+5hd %-+10.3hd   %- hd %- 5hd %- 10.3hd   %0hd %05hd %010hd "
              "%+0hd %+05hd %+010hd",
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num, 5,
              short_positive_num, 10, 3, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num);

  sprintf(buffer_2,
          "%hd %5hd %10.3hd %7.0hd %3.hd   %-hd %-*hd %-*.*hd   %-+hd %-+5hd "
          "%-+10.3hd   %- hd %- 5hd %- 10.3hd   %0hd %05hd %010hd %+0hd %+05hd "
          "%+010hd",
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num, 5,
          short_positive_num, 10, 3, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  // /* LONG INT TEST */
  char s21_buffer_3[250];
  char buffer_3[250];
  long int long_positive_num = 123456789;

  s21_sprintf(s21_buffer_3,
              "%ld %5ld %10.3ld %7.0ld %3.ld   %-ld %-*ld %-*.*ld   %-+ld "
              "%-+5ld %-+10.3ld   %-ld %- 5ld %- 10.3ld   %0ld %05ld %010ld "
              "%+0ld %+05ld %+010ld",
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num, 5,
              long_positive_num, 10, 3, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num);

  sprintf(buffer_3,
          "%ld %5ld %10.3ld %7.0ld %3.ld   %-ld %-*ld %-*.*ld   %-+ld %-+5ld "
          "%-+10.3ld   %-ld %- 5ld %- 10.3ld   %0ld %05ld %010ld %+0ld %+05ld "
          "%+010ld",
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num, 5,
          long_positive_num, 10, 3, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS INT SPECIFIER WITH NEGATIVE NUMBER */
START_TEST(test_s21_sprintf_int_specifier_negative_number) {
  /* INT TEST */
  char s21_buffer_1[250];
  char buffer_1[250];
  int negative_num = -12345;

  s21_sprintf(
      s21_buffer_1,
      "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   %- d "
      "%- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
      negative_num, negative_num, negative_num, negative_num, negative_num,
      negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
      negative_num, negative_num, negative_num, negative_num, negative_num,
      negative_num, negative_num, negative_num, negative_num, negative_num,
      negative_num);
  sprintf(buffer_1,
          "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   "
          "%- d %- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[250];
  char buffer_2[250];
  short int short_negative_num = -123;

  s21_sprintf(
      s21_buffer_2,
      "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   %- d "
      "%- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
      short_negative_num, short_negative_num, short_negative_num,
      short_negative_num, short_negative_num, short_negative_num, 5,
      short_negative_num, 10, 3, short_negative_num, short_negative_num,
      short_negative_num, short_negative_num, short_negative_num,
      short_negative_num, short_negative_num, short_negative_num,
      short_negative_num, short_negative_num, short_negative_num,
      short_negative_num, short_negative_num);
  sprintf(buffer_2,
          "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   "
          "%- d %- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num, 5,
          short_negative_num, 10, 3, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  // /* LONG INT TEST */
  char s21_buffer_3[400];
  char buffer_3[400];
  long int long_negative_num = -123456789;

  s21_sprintf(s21_buffer_3,
              "%ld %5ld %10.3ld %7.0ld %3.ld   %-ld %-*ld %-*.*ld   %-+ld "
              "%-+5ld %-+10.3ld   %-ld %- 5ld %- 10.3ld   %0ld %05ld %010ld "
              "%+0ld %+05ld %+010ld",
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num, 5,
              long_negative_num, 10, 3, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num);

  sprintf(buffer_3,
          "%ld %5ld %10.3ld %7.0ld %3.ld   %-ld %-*ld %-*.*ld   %-+ld %-+5ld "
          "%-+10.3ld   %-ld %- 5ld %- 10.3ld   %0ld %05ld %010ld %+0ld %+05ld "
          "%+010ld",
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num, 5,
          long_negative_num, 10, 3, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS INT SPECIFIER WITH ZERO NUMBER */
START_TEST(test_s21_sprintf_int_specifier_zero_number) {
  char s21_buffer[250];
  char buffer[250];
  int zero_num = 0;

  s21_sprintf(
      s21_buffer,
      "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   %- d "
      "%- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
      zero_num, zero_num, zero_num, zero_num, zero_num, zero_num, 5, zero_num,
      10, 3, zero_num, zero_num, zero_num, zero_num, zero_num, zero_num,
      zero_num, zero_num, zero_num, zero_num, zero_num, zero_num, zero_num);
  sprintf(buffer,
          "%d %5d %10.3d %7.0d %3.d   %-d %-*d %-*.*d   %-+d %-+5d %-+10.3d   "
          "%- d %- 5d %- 10.3d   %0d %05d %010d %+0d %+05d %+010d",
          zero_num, zero_num, zero_num, zero_num, zero_num, zero_num, 5,
          zero_num, 10, 3, zero_num, zero_num, zero_num, zero_num, zero_num,
          zero_num, zero_num, zero_num, zero_num, zero_num, zero_num, zero_num,
          zero_num);

  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

/* TESTS FLOAT SPECIFIER WITH POSITIVE NUMBER */
START_TEST(test_s21_sprintf_float_specifier_positive_number) {
  /* FLOAT TEST */
  char s21_buffer_1[600];
  char buffer_1[600];
  float float_positive_num = 186373.169479;

  s21_sprintf(
      s21_buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num, 5,
      float_positive_num, 10, 3, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num);

  sprintf(
      buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num, 5,
      float_positive_num, 10, 3, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num, float_positive_num,
      float_positive_num, float_positive_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* DOUBLE TEST */
  char s21_buffer_2[600];
  char buffer_2[600];
  double double_positive_num = 189654.169479913761920;

  s21_sprintf(
      s21_buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- .15f %- 5.1f %- 10.4f   %0f %05f %010f %+0f %+05f %+010f",
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num, 5,
      double_positive_num, 10, 3, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num);

  sprintf(
      buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- .15f %- 5.1f %- 10.4f   %0f %05f %010f %+0f %+05f %+010f",
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num, 5,
      double_positive_num, 10, 3, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num, double_positive_num,
      double_positive_num, double_positive_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG DOUBLE TEST #1*/
  char s21_buffer_3[1000];
  char buffer_3[1000];
  long double long_double_positive_num_1 = 1896937354.169479913761926;

  s21_sprintf(s21_buffer_3,
              "%Lf %5Lf %10.6Lf %7.0Lf %3.Lf   %-Lf %-*.8Lf %-*.*Lf   %-+Lf "
              "%-+5.15Lf %-+10.6Lf   %- Lf %- 5.1Lf %- 10.4Lf   %0Lf %05Lf "
              "%010Lf %+0Lf %+05Lf %+010Lf",
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1, 5,
              long_double_positive_num_1, 10, 3, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1,
              long_double_positive_num_1, long_double_positive_num_1);

  sprintf(buffer_3,
          "%Lf %5Lf %10.6Lf %7.0Lf %3.Lf   %-Lf %-*.8Lf %-*.*Lf   %-+Lf "
          "%-+5.15Lf %-+10.6Lf   %- Lf %- 5.1Lf %- 10.4Lf   %0Lf %05Lf %010Lf "
          "%+0Lf %+05Lf %+010Lf",
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1, 5,
          long_double_positive_num_1, 10, 3, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1,
          long_double_positive_num_1, long_double_positive_num_1);

  ck_assert_str_eq(s21_buffer_3, buffer_3);

  /* LONG DOUBLE TEST #2*/
  char s21_buffer_4[1000];
  char buffer_4[1000];
  long double long_double_positive_num_2 = 1973549659.192939495969798;

  s21_sprintf(s21_buffer_4,
              "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
              "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   "
              "%.13Lf %.14Lf %+0Lf %017Lf %0Lf %030Lf",
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2, 5,
              long_double_positive_num_2, 10, 15, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2,
              long_double_positive_num_2, long_double_positive_num_2);

  sprintf(buffer_4,
          "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
          "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   %.13Lf "
          "%.14Lf %+0Lf %017Lf %0Lf %030Lf",
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2, 5,
          long_double_positive_num_2, 10, 15, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2,
          long_double_positive_num_2, long_double_positive_num_2);

  ck_assert_str_eq(s21_buffer_4, buffer_4);

  /* LONG DOUBLE TEST #3*/
  char s21_buffer_5[1000];
  char buffer_5[1000];
  long double long_double_positive_num_3 = 1996399199.999199912999;

  s21_sprintf(s21_buffer_5,
              "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
              "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   "
              "%.13Lf %.14Lf %+0Lf %017Lf %0Lf %030Lf",
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3, 5,
              long_double_positive_num_3, 10, 15, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3,
              long_double_positive_num_3, long_double_positive_num_3);

  sprintf(buffer_5,
          "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
          "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   %.13Lf "
          "%.14Lf %+0Lf %017Lf %0Lf %030Lf",
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3, 5,
          long_double_positive_num_3, 10, 15, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3,
          long_double_positive_num_3, long_double_positive_num_3);

  ck_assert_str_eq(s21_buffer_5, buffer_5);
}
END_TEST

/* TESTS FLOAT SPECIFIER WITH NEGATIVE NUMBER */
START_TEST(test_s21_sprintf_float_specifier_negative_number) {
  /* FLOAT TEST */
  char s21_buffer_1[600];
  char buffer_1[600];
  float float_negative_num = -186373.169479;

  s21_sprintf(
      s21_buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num, 5,
      float_negative_num, 10, 3, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num);

  sprintf(
      buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num, 5,
      float_negative_num, 10, 3, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num, float_negative_num,
      float_negative_num, float_negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* DOUBLE TEST */
  char s21_buffer_2[600];
  char buffer_2[600];
  double double_negative_num = -189654.169479913761920;

  s21_sprintf(
      s21_buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- .15f %- 5.1f %- 10.4f   %0f %05f %010f %+0f %+05f %+010f",
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num, 5,
      double_negative_num, 10, 3, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num);

  sprintf(
      buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- .15f %- 5.1f %- 10.4f   %0f %05f %010f %+0f %+05f %+010f",
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num, 5,
      double_negative_num, 10, 3, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num, double_negative_num,
      double_negative_num, double_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG DOUBLE TEST #1*/
  char s21_buffer_3[1000];
  char buffer_3[1000];
  long double long_double_negative_num_1 = -1896937354.169479913761926;

  s21_sprintf(s21_buffer_3,
              "%Lf %5Lf %10.6Lf %7.0Lf %3.Lf   %-Lf %-*.8Lf %-*.*Lf   %-+Lf "
              "%-+5.15Lf %-+10.6Lf   %- Lf %- 5.1Lf %- 10.4Lf   %0Lf %05Lf "
              "%010Lf %+0Lf %+05Lf %+010Lf",
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1, 5,
              long_double_negative_num_1, 10, 3, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1,
              long_double_negative_num_1, long_double_negative_num_1);

  sprintf(buffer_3,
          "%Lf %5Lf %10.6Lf %7.0Lf %3.Lf   %-Lf %-*.8Lf %-*.*Lf   %-+Lf "
          "%-+5.15Lf %-+10.6Lf   %- Lf %- 5.1Lf %- 10.4Lf   %0Lf %05Lf %010Lf "
          "%+0Lf %+05Lf %+010Lf",
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1, 5,
          long_double_negative_num_1, 10, 3, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1,
          long_double_negative_num_1, long_double_negative_num_1);

  ck_assert_str_eq(s21_buffer_3, buffer_3);

  /* LONG DOUBLE TEST #2*/
  char s21_buffer_4[1000];
  char buffer_4[1000];
  long double long_double_negative_num_2 = -1973549659.192939495969798;

  s21_sprintf(s21_buffer_4,
              "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
              "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   "
              "%.13Lf %.14Lf %+0Lf %017Lf %0Lf %030Lf",
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2, 5,
              long_double_negative_num_2, 10, 15, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2,
              long_double_negative_num_2, long_double_negative_num_2);

  sprintf(buffer_4,
          "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
          "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   %.13Lf "
          "%.14Lf %+0Lf %017Lf %0Lf %030Lf",
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2, 5,
          long_double_negative_num_2, 10, 15, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2,
          long_double_negative_num_2, long_double_negative_num_2);

  ck_assert_str_eq(s21_buffer_4, buffer_4);

  /* LONG DOUBLE TEST #3*/
  char s21_buffer_5[1000];
  char buffer_5[1000];
  long double long_double_negative_num_3 = -1996399199.999199912999;

  s21_sprintf(s21_buffer_5,
              "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
              "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   "
              "%.13Lf %.14Lf %+0Lf %017Lf %0Lf %030Lf",
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3, 5,
              long_double_negative_num_3, 10, 15, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3,
              long_double_negative_num_3, long_double_negative_num_3);

  sprintf(buffer_5,
          "%.1Lf %5.2Lf %10.3Lf %7.0Lf %3.4Lf   %-.5Lf %-*.6Lf %-*.*Lf   "
          "%-+.7Lf %-+5.8Lf %-+10.9Lf   %- .10Lf %- 5.11Lf %- 10.12Lf   %.13Lf "
          "%.14Lf %+0Lf %017Lf %0Lf %030Lf",
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3, 5,
          long_double_negative_num_3, 10, 15, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3,
          long_double_negative_num_3, long_double_negative_num_3);

  ck_assert_str_eq(s21_buffer_5, buffer_5);
}
END_TEST

/* TESTS FLOAT SPECIFIER WITH ZERO NUMBER */
START_TEST(test_s21_sprintf_float_specifier_zero_number) {
  /* FLOAT TEST */
  char s21_buffer_1[600];
  char buffer_1[600];
  float float_zero_num = 0.0;

  s21_sprintf(
      s21_buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, 5, float_zero_num, 10, 3, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num);

  sprintf(
      buffer_1,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, 5, float_zero_num, 10, 3, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num,
      float_zero_num, float_zero_num, float_zero_num, float_zero_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* DOUBLE TEST */
  char s21_buffer_2[600];
  char buffer_2[600];
  double double_zero_num = 0.0;

  s21_sprintf(
      s21_buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, 5, double_zero_num, 10, 3,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num);

  sprintf(
      buffer_2,
      "%f %5f %10.6f %7.0f %3.f   %-f %-*.8f %-*.*f   %-+f %-+5.15f %-+10.6f   "
      "%- f %- 5.1f %- 10.4f   %0f %05f %020f %+30f %+05f %+010f",
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, 5, double_zero_num, 10, 3,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num, double_zero_num, double_zero_num, double_zero_num,
      double_zero_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);
}
END_TEST

/* TESTS STRING SPECIFIER */
START_TEST(test_s21_sprintf_string_specifier) {
  char s21_buffer[150];
  char buffer[150];
  char *string = "? | hello_world | ?";

  s21_sprintf(s21_buffer, "%s %-s %-20s %20s %.s %.5s %*.*s", string, string,
              string, string, string, string, 20, 3, string);
  sprintf(buffer, "%s %-s %-20s %20s %.s %.5s %*.*s", string, string, string,
          string, string, string, 20, 3, string);

  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

/* TESTS UINT SPECIFIER */
START_TEST(test_s21_sprintf_uint_specifier) {
  /* UNSIGNED INT TEST */
  char s21_buffer_1[300];
  char buffer_1[300];
  unsigned int positive_num = 12345;

  s21_sprintf(s21_buffer_1,
              "%ud %5ud %10.3ud %7.ud %3.ud   %-ud %-*ud %-*.*ud   %-5ud "
              "%-10.3ud   %-ud %-5ud %-10.3ud   %0ud %05ud %010ud %0ud",
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, 5, positive_num, 10, 3, positive_num,
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, positive_num, positive_num,
              positive_num);
  sprintf(buffer_1,
          "%ud %5ud %10.3ud %7.ud %3.ud   %-ud %-*ud %-*.*ud   %-5ud %-10.3ud  "
          " %-ud %-5ud %-10.3ud   %0ud %05ud %010ud %0ud",
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, 5, positive_num, 10, 3, positive_num, positive_num,
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, positive_num, positive_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* UNSIGNED SHORT INT TEST */
  char s21_buffer_2[300];
  char buffer_2[300];
  unsigned short int short_positive_num = 123;

  s21_sprintf(
      s21_buffer_2,
      "%hud %5hud %10.3hud %7.hud %3.hud   %-hud %-*hud %-*.*hud   %-5hud "
      "%-10.3hud   %-hud %-5hud %-10.3hud   %0hud %05hud %010hud %0hud",
      short_positive_num, short_positive_num, short_positive_num,
      short_positive_num, short_positive_num, short_positive_num, 5,
      short_positive_num, 10, 3, short_positive_num, short_positive_num,
      short_positive_num, short_positive_num, short_positive_num,
      short_positive_num, short_positive_num, short_positive_num,
      short_positive_num, short_positive_num);
  sprintf(buffer_2,
          "%hud %5hud %10.3hud %7.hud %3.hud   %-hud %-*hud %-*.*hud   %-5hud "
          "%-10.3hud   %-hud %-5hud %-10.3hud   %0hud %05hud %010hud %0hud",
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num, 5,
          short_positive_num, 10, 3, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* UNSIGNED LONG INT TEST */
  char s21_buffer_3[600];
  char buffer_3[600];
  unsigned long int long_positive_num = 12345678910;

  s21_sprintf(
      s21_buffer_3,
      "%lud %30lud %10.3lud %7.lud %3.lud   %-lud %-*lud %-*.*lud   %-20lud "
      "%-10.3lud   %-lud %-5lud %-10.3lud   %030lud %018lud %010lud %0lud",
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num, 5,
      long_positive_num, 10, 3, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num);
  sprintf(
      buffer_3,
      "%lud %30lud %10.3lud %7.lud %3.lud   %-lud %-*lud %-*.*lud   %-20lud "
      "%-10.3lud   %-lud %-5lud %-10.3lud   %030lud %018lud %010lud %0lud",
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num, 5,
      long_positive_num, 10, 3, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num, long_positive_num,
      long_positive_num, long_positive_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS PERCENT SPECIFIER */
START_TEST(test_s21_sprintf_percent_specifier) {
  char s21_buffer[100];
  char buffer[100];

  s21_sprintf(s21_buffer,
              "%%%%%% test %%%%%%%% %%%%%%%% test %%%% test %%%%%%%%%% %% test "
              "%%%%%% %%%%%%%%%%%%");
  sprintf(buffer,
          "%%%%%% test %%%%%%%% %%%%%%%% test %%%% test %%%%%%%%%% %% test "
          "%%%%%% %%%%%%%%%%%%");

  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

/* TESTS LOWER CASE HEX SPECIFIER WITH POSITIVE NUMBER*/
START_TEST(test_s21_sprintf_hex_specifier_lower_case_positive_number) {
  /* INT TEST */
  char s21_buffer_1[300];

  char buffer_1[300];

  int positive_num = 12345;

  s21_sprintf(s21_buffer_1,
              "%x %5x %10.3x %7.0x %3.x   %-x %-*x %-*.*x   %-5x %-10.3x  %0x "
              "%05x %010x %0x %05x %010x",
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, 5, positive_num, 10, 3, positive_num,
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, positive_num, positive_num);

  sprintf(buffer_1,
          "%x %5x %10.3x %7.0x %3.x   %-x %-*x %-*.*x   %-5x %-10.3x  %0x %05x "
          "%010x %0x %05x %010x",
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, 5, positive_num, 10, 3, positive_num, positive_num,
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, positive_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[300];

  char buffer_2[300];

  short int short_positive_num = 123;

  s21_sprintf(s21_buffer_2,
              "%hx %5hx %10.3hx %7.0hx %3.hx   %-hx %-*hx %-*.*hx   %-5hx "
              "%-10.3hx  %0hx %05hx %010hx %0hx %05hx %010hx",
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num, 5,
              short_positive_num, 10, 3, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num);

  sprintf(buffer_2,
          "%hx %5hx %10.3hx %7.0hx %3.hx   %-hx %-*hx %-*.*hx   %-5hx %-10.3hx "
          " %0hx %05hx %010hx %0hx %05hx %010hx",
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num, 5,
          short_positive_num, 10, 3, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[300];

  char buffer_3[300];

  long int long_positive_num = 123456789;

  s21_sprintf(s21_buffer_3,
              "%lx %5lx %10.3lx %7.0lx %3.lx   %-lx %-*lx %-*.*lx   %-5lx "
              "%-10.3lx  %0lx %05lx %010lx %0lx %05lx %010lx",
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num, 5,
              long_positive_num, 10, 3, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num);

  sprintf(buffer_3,
          "%lx %5lx %10.3lx %7.0lx %3.lx   %-lx %-*lx %-*.*lx   %-5lx %-10.3lx "
          " %0lx %05lx %010lx %0lx %05lx %010lx",
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num, 5,
          long_positive_num, 10, 3, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS LOWER CASE HEX SPECIFIER WITH NEGATIVE NUMBER*/
START_TEST(test_s21_sprintf_hex_specifier_lower_case_negative_number) {
  /* INT TEST */
  char s21_buffer_1[300];

  char buffer_1[300];

  int negative_num = -12345;

  s21_sprintf(s21_buffer_1,
              "%x %5x %10.3x %7.0x %3.x   %-x %-*x %-*.*x   %-5x %-10.3x  %0x "
              "%05x %010x %0x %05x %010x",
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, 5, negative_num, 10, 3, negative_num,
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, negative_num, negative_num);

  sprintf(buffer_1,
          "%x %5x %10.3x %7.0x %3.x   %-x %-*x %-*.*x   %-5x %-10.3x  %0x %05x "
          "%010x %0x %05x %010x",
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[600];

  char buffer_2[600];

  short int short_negative_num = -123;

  s21_sprintf(s21_buffer_2,
              "%hx %5hx %10.3hx %7.0hx %3.hx   %-hx %-*hx %-*.*hx   %-5hx "
              "%-10.3hx  %0hx %05hx %010hx %0hx %05hx %010hx",
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num, 5,
              short_negative_num, 10, 3, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num);

  sprintf(buffer_2,
          "%hx %5hx %10.3hx %7.0hx %3.hx   %-hx %-*hx %-*.*hx   %-5hx %-10.3hx "
          " %0hx %05hx %010hx %0hx %05hx %010hx",
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num, 5,
          short_negative_num, 10, 3, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[300];

  char buffer_3[300];

  long int long_negative_num = -123456789;

  s21_sprintf(s21_buffer_3,
              "%lx %5lx %10.3lx %7.0lx %3.lx   %-lx %-*lx %-*.*lx   %-5lx "
              "%-10.3lx  %0lx %05lx %010lx %0lx %05lx %010lx",
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num, 5,
              long_negative_num, 10, 3, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num);

  sprintf(buffer_3,
          "%lx %5lx %10.3lx %7.0lx %3.lx   %-lx %-*lx %-*.*lx   %-5lx %-10.3lx "
          " %0lx %05lx %010lx %0lx %05lx %010lx",
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num, 5,
          long_negative_num, 10, 3, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS UPPER CASE HEX SPECIFIER WITH POSITIVE NUMBER*/
START_TEST(test_s21_sprintf_hex_specifier_upper_case_positive_number) {
  /* INT TEST */
  char s21_buffer_1[300];

  char buffer_1[300];

  int positive_num = 12345;

  s21_sprintf(s21_buffer_1,
              "%X %5X %10.3X %7.0X %3.X   %-X %-*X %-*.*X   %-5X %-10.3X  %0X "
              "%05X %010X %0X %05X %010X",
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, 5, positive_num, 10, 3, positive_num,
              positive_num, positive_num, positive_num, positive_num,
              positive_num, positive_num, positive_num, positive_num);

  sprintf(buffer_1,
          "%X %5X %10.3X %7.0X %3.X   %-X %-*X %-*.*X   %-5X %-10.3X  %0X %05X "
          "%010X %0X %05X %010X",
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, 5, positive_num, 10, 3, positive_num, positive_num,
          positive_num, positive_num, positive_num, positive_num, positive_num,
          positive_num, positive_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[300];

  char buffer_2[300];

  short int short_positive_num = 123;

  s21_sprintf(s21_buffer_2,
              "%hX %5hX %10.3hX %7.0hX %3.hX   %-hX %-*hX %-*.*hX   %-5hX "
              "%-10.3hX  %0hX %05hX %010hX %0hX %05hX %010hX",
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num, 5,
              short_positive_num, 10, 3, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num, short_positive_num, short_positive_num,
              short_positive_num);

  sprintf(buffer_2,
          "%hX %5hX %10.3hX %7.0hX %3.hX   %-hX %-*hX %-*.*hX   %-5hX %-10.3hX "
          " %0hX %05hX %010hX %0hX %05hX %010hX",
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num, 5,
          short_positive_num, 10, 3, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num, short_positive_num, short_positive_num,
          short_positive_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[300];

  char buffer_3[300];

  long int long_positive_num = 123456789;

  s21_sprintf(s21_buffer_3,
              "%lX %5lX %10.3lX %7.0lX %3.lX   %-lX %-*lX %-*.*lX   %-5lX "
              "%-10.3lX  %0lX %05lX %010lX %0lX %05lX %010lX",
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num, 5,
              long_positive_num, 10, 3, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num, long_positive_num, long_positive_num,
              long_positive_num);

  sprintf(buffer_3,
          "%lX %5lX %10.3lX %7.0lX %3.lX   %-lX %-*lX %-*.*lX   %-5lX %-10.3lX "
          " %0lX %05lX %010lX %0lX %05lX %010lX",
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num, 5,
          long_positive_num, 10, 3, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num, long_positive_num, long_positive_num,
          long_positive_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS UPPER CASE HEX SPECIFIER WITH NEGATIVE NUMBER*/
START_TEST(test_s21_sprintf_hex_specifier_upper_case_negative_number) {
  /* INT TEST */
  char s21_buffer_1[300];

  char buffer_1[300];

  int negative_num = -12345;

  s21_sprintf(s21_buffer_1,
              "%X %5X %10.3X %7.0X %3.X   %-X %-*X %-*.*X   %-5X %-10.3X  %0X "
              "%05X %010X %0X %05X %010X",
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, 5, negative_num, 10, 3, negative_num,
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, negative_num, negative_num);

  sprintf(buffer_1,
          "%X %5X %10.3X %7.0X %3.X   %-X %-*X %-*.*X   %-5X %-10.3X  %0X %05X "
          "%010X %0X %05X %010X",
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[600];

  char buffer_2[600];

  short int short_negative_num = -123;

  s21_sprintf(s21_buffer_2,
              "%hX %5hX %10.3hX %7.0hX %3.hX   %-hX %-*hX %-*.*hX   %-5hX "
              "%-10.3hX  %0hX %05hX %010hX %0hX %05hX %010hX",
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num, 5,
              short_negative_num, 10, 3, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num);

  sprintf(buffer_2,
          "%hX %5hX %10.3hX %7.0hX %3.hX   %-hX %-*hX %-*.*hX   %-5hX %-10.3hX "
          " %0hX %05hX %010hX %0hX %05hX %010hX",
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num, 5,
          short_negative_num, 10, 3, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[300];

  char buffer_3[300];

  long int long_negative_num = -123456789;

  s21_sprintf(s21_buffer_3,
              "%lX %5lX %10.3lX %7.0lX %3.lX   %-lX %-*lX %-*.*lX   %-5lX "
              "%-10.3lX  %0lX %05lX %010lX %0lX %05lX %010lX",
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num, 5,
              long_negative_num, 10, 3, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num);

  sprintf(buffer_3,
          "%lX %5lX %10.3lX %7.0lX %3.lX   %-lX %-*lX %-*.*lX   %-5lX %-10.3lX "
          " %0lX %05lX %010lX %0lX %05lX %010lX",
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num, 5,
          long_negative_num, 10, 3, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS OCTAL SPECIFIER WITH POSITIVE NUMBER*/
START_TEST(test_s21_sprintf_octal_specifier_positive_number) {
  /* INT TEST */
  char s21_buffer_1[300];

  char buffer_1[300];

  int negative_num = 12345;

  s21_sprintf(s21_buffer_1,
              "%o %5o %10.3o %7.0o %3.o   %-o %-*o %-*.*o   %-5o %-10.3o  %0o "
              "%05o %010o %0o %05o %010o",
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, 5, negative_num, 10, 3, negative_num,
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, negative_num, negative_num);

  sprintf(buffer_1,
          "%o %5o %10.3o %7.0o %3.o   %-o %-*o %-*.*o   %-5o %-10.3o  %0o %05o "
          "%010o %0o %05o %010o",
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[600];

  char buffer_2[600];

  short int short_negative_num = 123;

  s21_sprintf(s21_buffer_2,
              "%ho %5ho %10.3ho %7.0ho %3.ho   %-ho %-*ho %-*.*ho   %-5ho "
              "%-10.3ho  %0ho %05ho %010ho %0ho %05ho %010ho",
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num, 5,
              short_negative_num, 10, 3, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num);

  sprintf(buffer_2,
          "%ho %5ho %10.3ho %7.0ho %3.ho   %-ho %-*ho %-*.*ho   %-5ho %-10.3ho "
          " %0ho %05ho %010ho %0ho %05ho %010ho",
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num, 5,
          short_negative_num, 10, 3, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[300];

  char buffer_3[300];

  long int long_negative_num = 123456789;

  s21_sprintf(s21_buffer_3,
              "%lo %5lo %10.3lo %7.0lo %3.lo   %-lo %-*lo %-*.*lo   %-5lo "
              "%-10.3lo  %0lo %05lo %010lo %0lo %05lo %010lo",
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num, 5,
              long_negative_num, 10, 3, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num);

  sprintf(buffer_3,
          "%lo %5lo %10.3lo %7.0lo %3.lo   %-lo %-*lo %-*.*lo   %-5lo %-10.3lo "
          " %0lo %05lo %010lo %0lo %05lo %010lo",
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num, 5,
          long_negative_num, 10, 3, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS OCTAL SPECIFIER WITH NEGATIVE NUMBER*/
START_TEST(test_s21_sprintf_octal_specifier_negative_number) {
  /* INT TEST */
  char s21_buffer_1[300];
  char buffer_1[300];
  int negative_num = -12345;

  s21_sprintf(s21_buffer_1,
              "%o %5o %10.3o %7.0o %3.o   %-o %-*o %-*.*o   %-5o %-10.3o  %0o "
              "%05o %010o %0o %05o %010o",
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, 5, negative_num, 10, 3, negative_num,
              negative_num, negative_num, negative_num, negative_num,
              negative_num, negative_num, negative_num, negative_num);

  sprintf(buffer_1,
          "%o %5o %10.3o %7.0o %3.o   %-o %-*o %-*.*o   %-5o %-10.3o  %0o %05o "
          "%010o %0o %05o %010o",
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, 5, negative_num, 10, 3, negative_num, negative_num,
          negative_num, negative_num, negative_num, negative_num, negative_num,
          negative_num, negative_num);

  ck_assert_str_eq(s21_buffer_1, buffer_1);

  /* SHORT INT TEST */
  char s21_buffer_2[600];
  char buffer_2[600];
  short int short_negative_num = -123;

  s21_sprintf(s21_buffer_2,
              "%ho %5ho %10.3ho %7.0ho %3.ho   %-ho %-*ho %-*.*ho   %-5ho "
              "%-10.3ho  %0ho %05ho %010ho %0ho %05ho %010ho",
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num, 5,
              short_negative_num, 10, 3, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num, short_negative_num, short_negative_num,
              short_negative_num);

  sprintf(buffer_2,
          "%ho %5ho %10.3ho %7.0ho %3.ho   %-ho %-*ho %-*.*ho   %-5ho %-10.3ho "
          " %0ho %05ho %010ho %0ho %05ho %010ho",
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num, 5,
          short_negative_num, 10, 3, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num, short_negative_num, short_negative_num,
          short_negative_num);

  ck_assert_str_eq(s21_buffer_2, buffer_2);

  /* LONG INT TEST */
  char s21_buffer_3[700];
  char buffer_3[700];
  long int long_negative_num = -123456789;

  s21_sprintf(s21_buffer_3,
              "%lo %5lo %10.3lo %7.0lo %3.lo   %-lo %-*lo %-*.*lo   %-5lo "
              "%-10.3lo  %0lo %05lo %010lo %0lo %05lo %010lo",
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num, 5,
              long_negative_num, 10, 3, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num, long_negative_num, long_negative_num,
              long_negative_num);

  sprintf(buffer_3,
          "%lo %5lo %10.3lo %7.0lo %3.lo   %-lo %-*lo %-*.*lo   %-5lo %-10.3lo "
          " %0lo %05lo %010lo %0lo %05lo %010lo",
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num, 5,
          long_negative_num, 10, 3, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num, long_negative_num, long_negative_num,
          long_negative_num);

  ck_assert_str_eq(s21_buffer_3, buffer_3);
}
END_TEST

/* TESTS POINTER ADDRESS SPECIFIER*/
START_TEST(test_s21_sprintf_pointer_address_specifier) {
  char s21_buffer[300];
  char buffer[300];

  int num = 123;
  void *addr = &num;

  s21_sprintf(s21_buffer, "%p %*p %p %15p %30p %-20p %35p", addr, 20, addr,
              addr, addr, addr, addr, addr);

  sprintf(buffer, "%p %*p %p %15p %30p %-20p %35p", addr, 20, addr, addr, addr,
          addr, addr, addr);

  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *create_s21_sprintf_suite(void) {
  Suite *s21_sprintf_suite;
  TCase *tc_core;

  s21_sprintf_suite = suite_create("s21_sprintf");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_s21_sprintf_char_specifier);

  tcase_add_test(tc_core, test_s21_sprintf_int_specifier_positive_number);
  tcase_add_test(tc_core, test_s21_sprintf_int_specifier_negative_number);
  tcase_add_test(tc_core, test_s21_sprintf_int_specifier_zero_number);

  tcase_add_test(tc_core, test_s21_sprintf_float_specifier_positive_number);
  tcase_add_test(tc_core, test_s21_sprintf_float_specifier_negative_number);
  tcase_add_test(tc_core, test_s21_sprintf_float_specifier_zero_number);

  tcase_add_test(tc_core, test_s21_sprintf_string_specifier);

  tcase_add_test(tc_core, test_s21_sprintf_uint_specifier);

  tcase_add_test(tc_core, test_s21_sprintf_percent_specifier);

  tcase_add_test(tc_core,
                 test_s21_sprintf_hex_specifier_lower_case_positive_number);
  tcase_add_test(tc_core,
                 test_s21_sprintf_hex_specifier_lower_case_negative_number);

  tcase_add_test(tc_core,
                 test_s21_sprintf_hex_specifier_upper_case_positive_number);
  tcase_add_test(tc_core,
                 test_s21_sprintf_hex_specifier_upper_case_negative_number);

  tcase_add_test(tc_core, test_s21_sprintf_octal_specifier_positive_number);
  tcase_add_test(tc_core, test_s21_sprintf_octal_specifier_negative_number);

  tcase_add_test(tc_core, test_s21_sprintf_pointer_address_specifier);

  suite_add_tcase(s21_sprintf_suite, tc_core);

  return s21_sprintf_suite;
}

int run_s21_sprintf_suite() {
  int tests_number_failed = 0;

  Suite *s21_sprintf_suite;
  SRunner *s21_sprintf_suite_srunner;

  s21_sprintf_suite = create_s21_sprintf_suite();

  s21_sprintf_suite_srunner = srunner_create(s21_sprintf_suite);

  srunner_set_fork_status(s21_sprintf_suite_srunner, CK_NOFORK);

  srunner_run_all(s21_sprintf_suite_srunner, CK_VERBOSE);

  tests_number_failed += srunner_ntests_failed(s21_sprintf_suite_srunner);
  srunner_free(s21_sprintf_suite_srunner);
  return tests_number_failed;
}