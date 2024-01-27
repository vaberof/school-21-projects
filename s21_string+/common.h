#ifndef COMMON_H
#define COMMON_H

#endif /* COMMON_H */

#ifndef STDBOOL_H
#include <stdbool.h>

#endif /* STDBOOL_H */

int s21_atoi(char *str_number);
char *s21_itoa(int number);
char *s21_lltoa(long long number);
char *s21_uitoa(unsigned long number);
char *s21_dtoa(long double number, int precision);
void conv_int_decimal_parts(long double number, int precision,
                            long double *int_part, long double *decimal_part);
char *s21_decimal_part_to_string(long long number, int precision);
char *s21_itohex(int num, bool is_lower_case);
char *s21_sitohex(short int num, bool is_lower_case);
char *s21_ltohex(long num, bool is_lower_case);
char *s21_ultohex(unsigned long int num);
char *s21_itooct(int num);
char *s21_sitooct(int num);
char *s21_ltooct(long num);
char *s21_reverse_string_number(char *str_number, bool is_negative);
bool s21_is_flag(char c);
bool s21_is_precision(char c);
bool s21_is_length(char c);
bool s21_is_specifier_prototype(char c);
bool s21_is_num(char c);
bool s21_is_passed_as_arg(char c);