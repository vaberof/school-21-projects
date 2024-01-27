#ifndef S21_STRING_H
#include "s21_string.h"

#endif /* S21_STRING_H */

#ifndef COMMON_H
#include "common.h"

#endif /* COMMON_H */

#ifndef STDBOOL_H
#include <stdbool.h>

#endif /* STDBOOL_H */

#ifndef STDLIB_H
#include <stdlib.h>

#endif /* STDLIB_H */

#ifndef STDARG_H
#include <stdarg.h>

#endif /* STDARG_H */

#ifndef MATH_H
#include <math.h>

#endif /* MATH_H */

#ifndef STDIO_H
#include <stdio.h>

#endif /* STDIO_H */

const int kDefaultDecimalPrecision = 6;

int s21_sprintf(char *str, const char *format, ...) {
  flags_t flags = {0};
  precision_t precision = {0};
  lengths_t lengths = {0};

  int width = 0;

  va_list args;
  va_start(args, format);
  s21_sprintf_parse_format(&str, &format, &args, &width, &precision, &flags,
                           &lengths);
  va_end(args);

  return 0;
}

/* FORMAT PARSING FUNCS */
void s21_sprintf_parse_format(char **buf, const char **format, va_list *args,
                              int *width, precision_t *precision,
                              flags_t *flags, lengths_t *lengths) {
  char specifier = '%';
  char *buf_copy = *buf;

  while (*format != NULL && **format != '\0') {
    if (s21_is_specifier_prototype(**format)) {
      (*format)++;

      s21_sprintf_parse_flags(format, flags);
      s21_sprintf_parse_width(format, args, width);
      s21_sprintf_parse_precision(format, args, precision);
      s21_sprintf_parse_length(format, lengths);
      s21_sprintf_parse_specifier(format, &specifier);

      s21_sprintf_proccess_buf(&buf_copy, flags, width, precision, lengths,
                               specifier, args);

      s21_reset_format_parameters(width, flags, precision, lengths);

      (*format)++;
    } else {
      *buf_copy = **format;
      buf_copy++;
      (*format)++;
    }
  }

  *buf_copy = '\0';
}

void s21_sprintf_parse_flags(const char **format, flags_t *flags) {
  while (**format && s21_is_flag(**format)) {
    s21_sprintf_process_flag(**format, flags);
    (*format)++;
  }
}

void s21_sprintf_process_flag(char flag, flags_t *flags) {
  switch (flag) {
    case kFlagMinus:
      flags->minus = true;
      break;
    case kFlagPlus:
      flags->plus = true;
      break;
    case kFlagSpace:
      flags->space = true;
      break;
    case kFlagSharp:
      flags->sharp = true;
      break;
    case kFlagZero:
      flags->zero = true;
      break;
    default:
      break;
  }
}

void s21_sprintf_parse_width(const char **format, va_list *args, int *width) {
  if (s21_is_passed_as_arg(**format)) {
    *width = va_arg(*args, int);
    (*format)++;
  } else {
    char *str_width = s21_sprintf_parse_number(format);
    *width = s21_atoi(str_width);
    free(str_width);
  }
}

void s21_sprintf_parse_precision(const char **format, va_list *args,
                                 precision_t *precision) {
  if (s21_is_precision(**format)) {
    precision->has_precision = true;
    (*format)++;
    if (s21_is_passed_as_arg(**format)) {
      precision->value = va_arg(*args, int);
      (*format)++;
    } else {
      char *str_precision = s21_sprintf_parse_number(format);
      precision->value = (*str_precision == '\0') ? 0 : atoi(str_precision);
      free(str_precision);
    }
  }
}

void s21_sprintf_parse_length(const char **format, lengths_t *lengths) {
  if (s21_is_length(**format)) {
    s21_sprintf_process_length(**format, lengths);
    (*format)++;
  }
}

void s21_sprintf_process_length(char length, lengths_t *lengths) {
  switch (length) {
    case kLengthShortIntShortUint:
      lengths->h = true;
      break;
    case kLengthLongIntLongUint:
      lengths->l = true;
      break;
    case kLengthLongDouble:
      lengths->L = true;
      break;
    default:
      break;
  }
}

void s21_sprintf_parse_specifier(const char **format, char *specifier) {
  *specifier = **format;
}

// returned value must be freed;
char *s21_sprintf_parse_number(const char **format) {
  int str_number_len = 1;
  char *str_number = malloc(sizeof(char) * str_number_len + 1);

  while (**format && s21_is_num(**format)) {
    str_number[str_number_len - 1] = **format;
    str_number = realloc(str_number, str_number_len + 1);
    (*format)++;
    str_number_len++;
  }

  str_number[str_number_len - 1] = '\0';

  return str_number;
}

void s21_reset_format_parameters(int *width, flags_t *flags,
                                 precision_t *precision, lengths_t *lengths) {
  *width = 0;
  flags = s21_memset(flags, 0, sizeof(flags));
  precision = s21_memset(precision, 0, sizeof(precision));
  lengths = s21_memset(lengths, 0, sizeof(lengths));
}

/* BUFFER PROCESSING FUNCS */
void s21_sprintf_proccess_buf(char **buf, flags_t *flags, int *width,
                              precision_t *precision, lengths_t *lengths,
                              char specifier, va_list *args) {
  bool is_lower_case;
  switch (specifier) {
    case kSpecifierChar:
      s21_process_char_specifier(buf, width, flags, args);
      break;
    case kSpecifierInt:
      s21_process_int_specifier(buf, width, flags, precision, lengths, args);
      break;
    case kSpecifierFloat:
      s21_process_double_specifier(buf, width, flags, precision, lengths, args);
      break;
    case kSpecifierString:
      s21_process_string_specifier(buf, width, flags, precision, args);
      break;
    case kSpecifierUint:
      s21_process_uint_specifier(buf, width, flags, precision, lengths, args);
      break;
    case kSpecifierPercent:
      s21_process_percent_specifier(buf);
      break;
    case kSpecifierLowerHex:
      is_lower_case = true;
      s21_process_hex_specifier(buf, is_lower_case, width, flags, precision,
                                lengths, args);
      break;
    case kSpecifierUpperHex:
      is_lower_case = false;
      s21_process_hex_specifier(buf, is_lower_case, width, flags, precision,
                                lengths, args);
      break;
    case kSpecifierOctal:
      s21_process_octal_specifier(buf, width, flags, precision, lengths, args);
      break;
    case kSpecifierPtrAddress:
      s21_process_ptr_specifier(buf, width, flags, args);
      break;
    default:
      break;
  }
}

void s21_process_char_specifier(char **buf, int *width, flags_t *flags,
                                va_list *args) {
  char c = va_arg(*args, int);
  s21_output_char_specifier_to_buf(buf, c, flags, width);
}

void s21_process_int_specifier(char **buf, int *width, flags_t *flags,
                               precision_t *precision, lengths_t *lengths,
                               va_list *args) {
  if (lengths->l) {
    long long_integer_number = va_arg(*args, long);
    s21_output_int_specifier_to_buf(buf, long_integer_number, flags, *width,
                                    precision, lengths);
  } else if (lengths->h) {
    short int short_integer_number = va_arg(*args, int);
    s21_output_int_specifier_to_buf(buf, short_integer_number, flags, *width,
                                    precision, lengths);
  } else {
    int integer_number = va_arg(*args, int);
    s21_output_int_specifier_to_buf(buf, integer_number, flags, *width,
                                    precision, lengths);
  }
}

void s21_process_double_specifier(char **buf, int *width, flags_t *flags,
                                  precision_t *precision, lengths_t *lengths,
                                  va_list *args) {
  if (lengths->L) {
    long double double_number = va_arg(*args, long double);
    s21_output_double_specifier_to_buf(buf, double_number, flags, *width,
                                       precision);
  } else {
    double double_number = va_arg(*args, double);
    s21_output_double_specifier_to_buf(buf, double_number, flags, *width,
                                       precision);
  }
}

void s21_process_string_specifier(char **buf, int *width, flags_t *flags,
                                  precision_t *precision, va_list *args) {
  char *string = va_arg(*args, char *);
  s21_output_string_specifier_to_buf(buf, string, flags, *width, precision);
}

void s21_process_uint_specifier(char **buf, int *width, flags_t *flags,
                                precision_t *precision, lengths_t *lengths,
                                va_list *args) {
  if (lengths->l) {
    unsigned long int uinteger_number = va_arg(*args, unsigned long int);
    s21_output_uint_specifier_to_buf(buf, uinteger_number, flags, *width,
                                     precision, lengths);
  } else if (lengths->h) {
    unsigned short int uinteger_number = va_arg(*args, int);
    s21_output_uint_specifier_to_buf(buf, uinteger_number, flags, *width,
                                     precision, lengths);
  } else {
    unsigned int uinteger_number = va_arg(*args, unsigned int);
    s21_output_uint_specifier_to_buf(buf, uinteger_number, flags, *width,
                                     precision, lengths);
  }
}

void s21_process_percent_specifier(char **buf) {
  s21_output_percent_pecifier_to_buf(buf);
}

void s21_process_hex_specifier(char **buf, bool is_lower_case, int *width,
                               flags_t *flags, precision_t *precision,
                               lengths_t *lengths, va_list *args) {
  if (lengths->l) {
    long long_integer_number = va_arg(*args, long);
    s21_output_hex_specifier_to_buf(buf, is_lower_case, long_integer_number,
                                    flags, *width, precision, lengths);
  } else if (lengths->h) {
    short int short_integer_number = va_arg(*args, int);
    s21_output_hex_specifier_to_buf(buf, is_lower_case, short_integer_number,
                                    flags, *width, precision, lengths);
  } else {
    int integer_number = va_arg(*args, int);
    s21_output_hex_specifier_to_buf(buf, is_lower_case, integer_number, flags,
                                    *width, precision, lengths);
  }
}

void s21_process_octal_specifier(char **buf, int *width, flags_t *flags,
                                 precision_t *precision, lengths_t *lengths,
                                 va_list *args) {
  if (lengths->l) {
    long long_integer_number = va_arg(*args, long);
    s21_output_octal_specifier_to_buf(buf, long_integer_number, flags, *width,
                                      precision, lengths);
  } else if (lengths->h) {
    short int short_integer_number = va_arg(*args, int);
    s21_output_octal_specifier_to_buf(buf, short_integer_number, flags, *width,
                                      precision, lengths);
  } else {
    int integer_number = va_arg(*args, int);
    s21_output_octal_specifier_to_buf(buf, integer_number, flags, *width,
                                      precision, lengths);
  }
}

void s21_process_ptr_specifier(char **buf, int *width, flags_t *flags,
                               va_list *args) {
  unsigned long int ptr = (unsigned long int)va_arg(*args, void *);
  s21_output_ptr_specifier_to_buf(buf, ptr, flags, width);
}

void s21_output_char_specifier_to_buf(char **buf, char c, flags_t *flags,
                                      int *width) {
  if (flags->minus) {
    **buf = c;
    (*buf)++;
    s21_output_width_to_buf(buf, (*width) - 1, flags);
  } else {
    s21_output_width_to_buf(buf, (*width) - 1, flags);
    **buf = c;
    (*buf)++;
  }
}

void s21_output_int_specifier_to_buf(char **buf, long number, flags_t *flags,
                                     int width, precision_t *precision,
                                     lengths_t *lengths) {
  if (s21_must_not_output_int_to_buf(number, precision)) {
    s21_output_int_no_character_to_buf(buf, number, flags, width);
    return;
  }

  if (lengths->h) {
    short int short_number = number;
    char *str_short_number = s21_itoa(short_number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_str_number_to_buf(
        buf, str_short_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags);
    free(str_short_number);
  } else {
    char *str_number = s21_lltoa(number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_number);
    s21_process_output_str_number_to_buf(
        buf, str_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_number), flags);
    free(str_number);
  }
}

void s21_output_int_no_character_to_buf(char **buf, long number, flags_t *flags,
                                        int width) {
  width = (flags->plus) ? width - 1 : width;
  char *str_number = s21_itoa(number);

  if (flags->minus) {
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    s21_output_width_to_buf(buf, width, flags);
    s21_output_sign_to_buf(buf, str_number, flags);
  }

  free(str_number);
}

void s21_output_double_specifier_to_buf(char **buf, long double number,
                                        flags_t *flags, int width,
                                        precision_t *precision) {
  if (flags->space && number >= 0) {
    **buf = ' ';
    (*buf)++;
    width--;
  }
  width = (flags->plus && number >= 0) ? width - 1 : width;

  char *str_number =
      s21_dtoa(number, precision->has_precision ? precision->value
                                                : kDefaultDecimalPrecision);

  size_t str_number_len = s21_strlen(str_number);

  if (s21_strchr(str_number, '.') == NULL && flags->sharp) {
    str_number = realloc(str_number, (int)str_number_len + 2);
    str_number[str_number_len] = '.';
    str_number[str_number_len + 1] = '\0';
    str_number_len += 1;
  }

  if (flags->minus) {
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_str_number_to_buf(buf, str_number);
    s21_output_width_to_buf(buf, width - (int)str_number_len, flags);
  } else if (flags->zero) {
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_width_to_buf(buf, width - (int)str_number_len, flags);
    s21_output_str_number_to_buf(buf, str_number);
  } else {
    s21_output_width_to_buf(buf, width - (int)str_number_len, flags);
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_str_number_to_buf(buf, str_number);
  }

  free(str_number);
}

void s21_output_string_specifier_to_buf(char **buf, char *string,
                                        flags_t *flags, int width,
                                        precision_t *precision) {
  size_t string_copy_length =
      (precision->has_precision) ? precision->value : (int)s21_strlen(string);
  char *string_copy = malloc(sizeof(char) * string_copy_length + 1);
  string_copy = s21_memcpy(string_copy, string, (int)string_copy_length);

  string_copy[string_copy_length] = '\0';

  if (flags->minus) {
    s21_output_str_to_buf(buf, string_copy);
    s21_output_width_to_buf(buf, width - s21_strlen(string_copy), flags);
  } else {
    s21_output_width_to_buf(buf, width - s21_strlen(string_copy), flags);
    s21_output_str_to_buf(buf, string_copy);
  }

  free(string_copy);
}

void s21_output_uint_specifier_to_buf(char **buf, unsigned long number,
                                      flags_t *flags, int width,
                                      precision_t *precision,
                                      lengths_t *lengths) {
  if (s21_must_not_output_uint_to_buf(number, precision)) {
    s21_output_uint_no_character_to_buf(buf, number, flags, width);
    return;
  }

  if (lengths->l) {
    char *str_long_number = s21_uitoa(number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_long_number);
    s21_process_output_str_number_to_buf(
        buf, str_long_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_long_number), flags);
    free(str_long_number);
  } else if (lengths->h) {
    unsigned int short_number = number;
    char *str_short_number = s21_uitoa(short_number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_str_number_to_buf(
        buf, str_short_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags);
    free(str_short_number);
  } else {
    char *str_number = s21_uitoa(number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_number);
    s21_process_output_str_number_to_buf(
        buf, str_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_number), flags);
    free(str_number);
  }
}

void s21_output_uint_no_character_to_buf(char **buf, unsigned long number,
                                         flags_t *flags, int width) {
  width = (flags->plus) ? width - 1 : width;
  char *str_number = s21_uitoa(number);

  if (flags->minus) {
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    s21_output_width_to_buf(buf, width, flags);
    s21_output_sign_to_buf(buf, str_number, flags);
  }

  free(str_number);
}

void s21_output_percent_pecifier_to_buf(char **buf) {
  **buf = '%';
  (*buf)++;
}

void s21_output_hex_specifier_to_buf(char **buf, bool is_lower_case,
                                     long number, flags_t *flags, int width,
                                     precision_t *precision,
                                     lengths_t *lengths) {
  if (s21_must_not_output_int_to_buf(number, precision)) {
    s21_output_base16_int_no_character_to_buf(buf, flags, width);
    return;
  }
  if (lengths->h) {
    short int short_number = number;
    char *str_short_number = s21_sitohex(short_number, is_lower_case);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_hex_number_to_buf(
        buf, str_short_number, is_lower_case, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags);
    free(str_short_number);
  } else if (lengths->l) {
    char *str_number = s21_ltohex(number, is_lower_case);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_number);
    s21_process_output_hex_number_to_buf(
        buf, str_number, is_lower_case, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_number), flags);
    free(str_number);
  } else {
    int int_number = number;
    char *str_short_number = s21_itohex(int_number, is_lower_case);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_hex_number_to_buf(
        buf, str_short_number, is_lower_case, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags);
    free(str_short_number);
  }
}

void s21_output_base16_int_no_character_to_buf(char **buf, flags_t *flags,
                                               int width) {
  width = (flags->sharp) ? width - 2 : width;
  if (flags->minus) {
    s21_output_width_to_buf(buf, width, flags);
  } else {
    s21_output_width_to_buf(buf, width, flags);
  }
}

void s21_output_octal_specifier_to_buf(char **buf, long number, flags_t *flags,
                                       int width, precision_t *precision,
                                       lengths_t *lengths) {
  if (s21_must_not_output_int_to_buf(number, precision)) {
    s21_output_base8_int_no_character_to_buf(buf, flags, precision, width);
    return;
  }

  if (lengths->h) {
    short int short_number = number;
    char *str_short_number = s21_sitooct(short_number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_octal_number_to_buf(
        buf, str_short_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags,
        precision);
    free(str_short_number);
  } else if (lengths->l) {
    char *str_number = s21_ltooct(number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_number);
    s21_process_output_octal_number_to_buf(
        buf, str_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_number), flags,
        precision);
    free(str_number);
  } else {
    int int_number = number;
    char *str_short_number = s21_itooct(int_number);
    int leading_zeros_count =
        s21_get_leading_zeros_count(precision, str_short_number);
    s21_process_output_octal_number_to_buf(
        buf, str_short_number, leading_zeros_count,
        (width)-leading_zeros_count - (int)s21_strlen(str_short_number), flags,
        precision);
    free(str_short_number);
  }
}

void s21_output_base8_int_no_character_to_buf(char **buf, flags_t *flags,
                                              precision_t *precision,
                                              int width) {
  width = (flags->sharp) ? width - 1 : width;
  if (flags->minus) {
    s21_output_octal_prefix_to_buf(buf, "", flags, precision);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    s21_output_width_to_buf(buf, width, flags);
    s21_output_octal_prefix_to_buf(buf, "", flags, precision);
  }
}

void s21_output_ptr_specifier_to_buf(char **buf, unsigned long int num,
                                     flags_t *flags, int *width) {
  char *str_ptr = s21_ultohex(num);
  *width = (*width) - 2;

  if (flags->minus) {
    s21_output_hex_ptr_prefix_to_buf(buf);
    s21_output_str_to_buf(buf, str_ptr);
    s21_output_width_to_buf(buf, (*width) - (int)s21_strlen(str_ptr), flags);
  } else {
    s21_output_width_to_buf(buf, (*width) - (int)s21_strlen(str_ptr), flags);
    s21_output_hex_ptr_prefix_to_buf(buf);
    s21_output_str_to_buf(buf, str_ptr);
  }

  free(str_ptr);
}

void s21_process_output_str_number_to_buf(char **buf, char *str_number,
                                          int leading_zeros_count, int width,
                                          flags_t *flags) {
  if (flags->space && *str_number != '-') {
    **buf = ' ';
    (*buf)++;
    width--;
  }
  width = (flags->plus && *str_number != '-') ? width - 1 : width;

  if (flags->minus) {
    s21_output_sign_to_buf(buf, str_number, flags);
    s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
    s21_output_str_number_to_buf(buf, str_number);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    if (flags->zero) {
      s21_output_sign_to_buf(buf, str_number, flags);
      s21_output_width_to_buf(buf, width, flags);
      // s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
      s21_output_str_number_to_buf(buf, str_number);
    } else {
      s21_output_width_to_buf(buf, width, flags);
      s21_output_sign_to_buf(buf, str_number, flags);
      s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
      s21_output_str_number_to_buf(buf, str_number);
    }
  }
}

void s21_process_output_hex_number_to_buf(char **buf, char *str_number,
                                          bool is_lower_case,
                                          int leading_zeros_count, int width,
                                          flags_t *flags) {
  width = (flags->sharp && *str_number != '0') ? width - 2 : width;

  if (flags->minus) {
    s21_output_hex_prefix_to_buf(buf, str_number, is_lower_case, flags);
    s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
    s21_output_str_number_to_buf(buf, str_number);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    if (flags->zero) {
      s21_output_hex_prefix_to_buf(buf, str_number, is_lower_case, flags);
      s21_output_width_to_buf(buf, width, flags);
    } else {
      s21_output_width_to_buf(buf, width, flags);
      s21_output_hex_prefix_to_buf(buf, str_number, is_lower_case, flags);
    }

    s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
    s21_output_str_number_to_buf(buf, str_number);
  }
}

void s21_process_output_octal_number_to_buf(char **buf, char *str_number,
                                            int leading_zeros_count, int width,
                                            flags_t *flags,
                                            precision_t *precision) {
  width = (flags->sharp && *str_number != '0') ? width - 1 : width;

  if (flags->minus) {
    s21_output_octal_prefix_to_buf(buf, str_number, flags, precision);
    s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
    s21_output_str_number_to_buf(buf, str_number);
    s21_output_width_to_buf(buf, width, flags);
  } else {
    s21_output_width_to_buf(buf, width, flags);
    s21_output_octal_prefix_to_buf(buf, str_number, flags, precision);
    s21_output_leading_zeros_to_buf(buf, leading_zeros_count);
    s21_output_str_number_to_buf(buf, str_number);
  }
}

void s21_output_leading_zeros_to_buf(char **buf, int leading_zeros_count) {
  while (leading_zeros_count > 0) {
    **buf = '0';
    (*buf)++;
    leading_zeros_count--;
  }
}

int s21_get_leading_zeros_count(precision_t *precision, char *str_number) {
  int leading_zeros_count =
      precision->has_precision ? precision->value - s21_strlen(str_number) : 0;

  if (precision->has_precision && *str_number == '-') {
    leading_zeros_count++;
  }

  return leading_zeros_count < 0 ? 0 : leading_zeros_count;
}

void s21_output_str_number_to_buf(char **buf, char *str) {
  while (*str != '\0') {
    if (*str != '-') {
      **buf = *str;
      (*buf)++;
      str++;
    } else {
      str++;
    }
  }
}

void s21_output_str_to_buf(char **buf, char *str) {
  while (*str != '\0') {
    **buf = *str;
    (*buf)++;
    str++;
  }
}

void s21_output_sign_to_buf(char **buf, char *str_number, flags_t *flags) {
  if (*str_number == '-') {
    **buf = '-';
    (*buf)++;
  } else if (flags->plus) {
    if (s21_is_num(*str_number)) {
      **buf = '+';
      (*buf)++;
    }
  }
}

void s21_output_width_to_buf(char **buf, int width, flags_t *flags) {
  for (int i = 0; i < width; i++) {
    if (flags->zero) {
      **buf = '0';
      (*buf)++;
    } else {
      **buf = ' ';
      (*buf)++;
    }
  }
}

void s21_output_hex_prefix_to_buf(char **buf, char *str_number,
                                  bool is_lower_case, flags_t *flags) {
  if (flags->sharp && *str_number != '0') {
    **buf = '0';
    (*buf)++;
    **buf = is_lower_case ? 'x' : 'X';
    (*buf)++;
  }
}

void s21_output_hex_ptr_prefix_to_buf(char **buf) {
  **buf = '0';
  (*buf)++;
  **buf = 'x';
  (*buf)++;
}

void s21_output_octal_prefix_to_buf(char **buf, char *str_number,
                                    flags_t *flags, precision_t *precision) {
  if (flags->sharp && *str_number != '0') {
    if (!precision->has_precision ||
        (precision->has_precision &&
         precision->value <= (int)s21_strlen(str_number))) {
      **buf = '0';
      (*buf)++;
    }
  }
}

bool s21_must_not_output_int_to_buf(long number, precision_t *precision) {
  return (precision->has_precision && precision->value == 0 && number == 0);
}

bool s21_must_not_output_uint_to_buf(unsigned long number,
                                     precision_t *precision) {
  return (precision->has_precision && precision->value == 0 && number == 0);
}
