#ifndef COMMON_H
#include "common.h"

#endif /* COMMON_H */

#ifndef S21_STRING_H
#include "s21_string.h"

#endif /* S21_STRING_H */

#ifndef STDLIB_H
#include <stdlib.h>

#endif /* STDLIB_H */

#ifndef MATH_H
#include <math.h>

#endif /* MATH_H */

#ifndef STDIO_H
#include <stdio.h>

#endif /* STDIO_H */

int s21_atoi(char *str_number) {
  size_t str_number_len = s21_strlen(str_number);
  int converted_number = 0;

  bool is_negaive = (str_number_len > 0 && str_number[0] == '-') ? true : false;

  for (size_t i = 0; i < str_number_len; i++) {
    if (s21_is_num(str_number[i])) {
      converted_number = converted_number * 10 + (str_number[i] - '0');
    }
  }

  return is_negaive ? -converted_number : converted_number;
}

// returned value must be freed;
char *s21_itoa(int number) {
  size_t str_number_len = 1;
  char *converted_str_number =
      malloc(sizeof(char) * (str_number_len + (size_t)1));
  converted_str_number = s21_memset(
      converted_str_number, 0, sizeof(char) * (str_number_len + (size_t)1));

  if (number == 0) {
    converted_str_number[str_number_len - 1] = '0';
    str_number_len++;
  }

  bool is_negative = false;

  if (number < 0) {
    is_negative = true;
    number = -number;
    converted_str_number[str_number_len - 1] = '-';

    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;
    str_number_len++;
  }
  while (number > 0) {
    converted_str_number[str_number_len - 1] = (number % 10) + '0';
    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;

    str_number_len++;
    number /= 10;
  }

  converted_str_number[str_number_len - 1] = '\0';

  return s21_reverse_string_number(converted_str_number, is_negative);
}

// returned value must be freed;
char *s21_lltoa(long long number) {
  size_t str_number_len = 1;
  char *converted_str_number =
      malloc(sizeof(char) * (str_number_len + (size_t)1));
  converted_str_number = s21_memset(
      converted_str_number, 0, sizeof(char) * (str_number_len + (size_t)1));

  if (number == 0) {
    converted_str_number[str_number_len - 1] = '0';
    str_number_len++;
  }

  bool is_negative = false;

  if (number < 0) {
    is_negative = true;
    number = -number;
    converted_str_number[str_number_len - 1] = '-';
    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;
    str_number_len++;
  }
  while (number > 0) {
    converted_str_number[str_number_len - 1] = (number % 10) + '0';
    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;
    str_number_len++;
    number /= 10;
  }

  converted_str_number[str_number_len - 1] = '\0';

  return s21_reverse_string_number(converted_str_number, is_negative);
}

// returned value must be freed;
char *s21_uitoa(unsigned long number) {
  size_t str_number_len = 1;
  char *converted_str_number =
      malloc(sizeof(char) * (str_number_len + (size_t)1));
  converted_str_number = s21_memset(
      converted_str_number, 0, sizeof(char) * (str_number_len + (size_t)1));

  if (number == 0) {
    converted_str_number[str_number_len - 1] = '0';
    str_number_len++;
  }

  while (number > 0) {
    converted_str_number[str_number_len - 1] = (number % 10) + '0';
    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;
    str_number_len++;
    number /= 10;
  }

  converted_str_number[str_number_len - 1] = '\0';

  bool is_negative = false;

  return s21_reverse_string_number(converted_str_number, is_negative);
}

// returned value must be freed;
char *s21_dtoa(long double number, int precision) {
  long double int_part = 0;
  long double decimal_part = 0.0;

  conv_int_decimal_parts(number, precision, &int_part, &decimal_part);

  char *string_int_part = s21_lltoa(int_part);

  char *string_decimal_part =
      s21_decimal_part_to_string(decimal_part, precision);

  size_t string_int_part_len = s21_strlen(string_int_part);
  size_t string_decimal_part_len = s21_strlen(string_decimal_part);

  char *converted_number =
      malloc(sizeof(char) *
             (string_int_part_len + string_decimal_part_len + (size_t)2));
  converted_number =
      s21_memset(converted_number, 0,
                 sizeof(char) * (string_int_part_len + string_decimal_part_len +
                                 (size_t)2));

  if (precision == 0) {
    converted_number =
        s21_memcpy(converted_number, string_int_part, string_int_part_len);
  } else {
    converted_number =
        s21_memcpy(converted_number, string_int_part, string_int_part_len);
    converted_number[string_int_part_len] = '.';
    converted_number[string_int_part_len + 1] = '\0';
    converted_number = s21_strncat(converted_number, string_decimal_part,
                                   string_decimal_part_len);
  }

  free(string_int_part);
  free(string_decimal_part);

  return converted_number;
}

void conv_int_decimal_parts(long double number, int precision,
                            long double *int_part, long double *decimal_part) {
  long double moving_decimal_point = powl(10.0, precision);

  bool is_negative = false;

  if (number < 0) {
    is_negative = true;
    number = -number;
  }

  (*decimal_part) = modfl(number, int_part);

  (*decimal_part) *= moving_decimal_point;
  (*decimal_part) = roundl(*decimal_part);

  if ((*decimal_part) == moving_decimal_point) {
    (*int_part) += 1;
    (*decimal_part) = 0;
  }

  if (is_negative) {
    (*int_part) = -(*int_part);
  }
}

// returned value must be freed;
char *s21_decimal_part_to_string(long long number, int precision) {
  size_t str_number_len = 1;
  char *converted_str_number =
      malloc(sizeof(char) * (str_number_len + (size_t)1));
  converted_str_number = s21_memset(
      converted_str_number, 0, sizeof(char) * (str_number_len + (size_t)1));

  if (number == 0) {
    converted_str_number[str_number_len - 1] = '0';
    str_number_len++;
    precision--;
    while (precision > 0) {
      converted_str_number[str_number_len - 1] = '0';
      char *buf = realloc(converted_str_number,
                          sizeof(char) * (str_number_len + (size_t)1));
      converted_str_number = buf;
      str_number_len++;
      precision--;
    }
  }

  while (number > 0) {
    converted_str_number[str_number_len - 1] = (number % 10) + '0';
    char *buf = realloc(converted_str_number,
                        sizeof(char) * (str_number_len + (size_t)1));
    converted_str_number = buf;
    str_number_len++;
    number /= 10;
  }

  converted_str_number[str_number_len - 1] = '\0';

  return s21_reverse_string_number(converted_str_number, false);
}

// returned value must be freed
char *s21_itohex(int num, bool is_lower_case) {
  size_t str_hex_len = 1;
  char *str_hex = malloc(sizeof(char) * (str_hex_len + (size_t)1));
  str_hex = s21_memset(str_hex, 0, sizeof(char) * (str_hex_len + (size_t)1));

  if (num == 0) {
    str_hex[str_hex_len - 1] = '0';
    str_hex_len++;
  }

  if (num > 0) {
    while (num > 0) {
      int remainder = num % 16;

      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }

      str_hex_len++;
      num /= 16;
    }
  } else {
    unsigned int uint_num = num;
    while (uint_num > 0) {
      long remainder = uint_num % 16;
      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }
      str_hex_len++;
      uint_num /= 16;
    }
  }
  str_hex[str_hex_len - 1] = '\0';
  return s21_reverse_string_number(str_hex, false);
}

// returned value must be freed
char *s21_sitohex(short int num, bool is_lower_case) {
  size_t str_hex_len = 1;
  char *str_hex = malloc(sizeof(char) * (str_hex_len + (size_t)1));
  str_hex = s21_memset(str_hex, 0, sizeof(char) * (str_hex_len + (size_t)1));

  if (num == 0) {
    str_hex[str_hex_len - 1] = '0';
    str_hex_len++;
  }

  if (num > 0) {
    while (num > 0) {
      int remainder = num % 16;

      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }

      str_hex_len++;
      num /= 16;
    }
  } else {
    unsigned short int uint_num = num;
    while (uint_num > 0) {
      long remainder = uint_num % 16;
      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }
      str_hex_len++;
      uint_num /= 16;
    }
  }
  str_hex[str_hex_len - 1] = '\0';
  return s21_reverse_string_number(str_hex, false);
}

// returned value must be freed
char *s21_ltohex(long num, bool is_lower_case) {
  size_t str_hex_len = 1;
  char *str_hex = malloc(sizeof(char) * (str_hex_len + (size_t)1));
  str_hex = s21_memset(str_hex, 0, sizeof(char) * (str_hex_len + (size_t)1));

  if (num == 0) {
    str_hex[str_hex_len - 1] = '0';
    str_hex_len++;
  }

  if (num > 0) {
    while (num > 0) {
      long remainder = num % 16;
      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }
      str_hex_len++;
      num /= 16;
    }
  } else {
    unsigned long int uint_num = num;
    while (uint_num > 0) {
      long remainder = uint_num % 16;
      if (remainder < 10) {
        str_hex[str_hex_len - 1] = remainder + '0';
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      } else {
        str_hex[str_hex_len - 1] =
            is_lower_case ? remainder + 'a' - 10 : remainder + 'A' - 10;
        char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
        str_hex = buf;
      }

      str_hex_len++;
      uint_num /= 16;
    }
  }
  str_hex[str_hex_len - 1] = '\0';
  return s21_reverse_string_number(str_hex, false);
}

// returned value must be freed
char *s21_ultohex(unsigned long int num) {
  size_t str_hex_len = 1;
  char *str_hex = malloc(sizeof(char) * (str_hex_len + (size_t)1));
  str_hex = s21_memset(str_hex, 0, sizeof(char) * (str_hex_len + (size_t)1));

  if (num == 0) {
    str_hex[str_hex_len - 1] = '0';
    str_hex_len++;
  }

  while (num > 0) {
    unsigned long int remainder = num % 16;
    if (remainder < 10) {
      str_hex[str_hex_len - 1] = remainder + '0';
      char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
      str_hex = buf;
    } else {
      str_hex[str_hex_len - 1] = remainder + 'a' - 10;
      char *buf = realloc(str_hex, sizeof(char) * (str_hex_len + (size_t)1));
      str_hex = buf;
    }

    str_hex_len++;
    num /= 16;
  }

  str_hex[str_hex_len - 1] = '\0';
  return s21_reverse_string_number(str_hex, false);
}

// returned value must be freed
char *s21_itooct(int num) {
  size_t str_oct_len = 1;
  char *str_oct = malloc(sizeof(char) * (str_oct_len + (size_t)1));
  str_oct = s21_memset(str_oct, 0, sizeof(char) * (str_oct_len + (size_t)1));

  if (num == 0) {
    str_oct[str_oct_len - 1] = '0';
    str_oct_len++;
  }

  if (num > 0) {
    while (num > 0) {
      int remainder = num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      num /= 8;
    }
  } else {
    unsigned int uint_num = num;
    while (uint_num > 0) {
      int remainder = uint_num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      uint_num /= 8;
    }
  }

  str_oct[str_oct_len - 1] = '\0';

  return s21_reverse_string_number(str_oct, false);
}

// returned value must be freed
char *s21_sitooct(int num) {
  size_t str_oct_len = 1;
  char *str_oct = malloc(sizeof(char) * (str_oct_len + (size_t)1));
  str_oct = s21_memset(str_oct, 0, sizeof(char) * (str_oct_len + (size_t)1));

  if (num == 0) {
    str_oct[str_oct_len - 1] = '0';
    str_oct_len++;
  }

  if (num > 0) {
    while (num > 0) {
      int remainder = num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      num /= 8;
    }
  } else {
    unsigned short int uint_num = num;
    while (uint_num > 0) {
      int remainder = uint_num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      uint_num /= 8;
    }
  }

  str_oct[str_oct_len - 1] = '\0';

  return s21_reverse_string_number(str_oct, false);
}

// returned value must be freed
char *s21_ltooct(long num) {
  size_t str_oct_len = 1;
  char *str_oct = malloc(sizeof(char) * (str_oct_len + (size_t)1));
  str_oct = s21_memset(str_oct, 0, sizeof(char) * (str_oct_len + (size_t)1));

  if (num == 0) {
    str_oct[str_oct_len - 1] = '0';
    str_oct_len++;
  }

  if (num > 0) {
    while (num > 0) {
      int remainder = num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      num /= 8;
    }
  } else {
    unsigned long int uint_num = num;

    while (uint_num > 0) {
      long remainder = uint_num % 8;

      str_oct[str_oct_len - 1] = remainder + '0';
      char *buf = realloc(str_oct, sizeof(char) * (str_oct_len + (size_t)1));
      str_oct = buf;

      str_oct_len++;
      uint_num /= 8;
    }
  }

  str_oct[str_oct_len - 1] = '\0';

  return s21_reverse_string_number(str_oct, false);
}

char *s21_reverse_string_number(char *str_number, bool is_negative) {
  size_t str_number_len = s21_strlen(str_number);

  size_t start = is_negative ? 1 : 0;
  size_t end = str_number_len - 1;

  while (start < end) {
    char temp = str_number[start];
    str_number[start] = str_number[end];
    str_number[end] = temp;

    start++;
    end--;
  }

  return str_number;
}

bool s21_is_flag(char c) {
  return (c == kFlagMinus || c == kFlagPlus || c == kFlagSpace ||
          c == kFlagSharp || c == kFlagZero);
}

bool s21_is_precision(char c) { return (c == '.'); }

bool s21_is_length(char c) {
  return (c == kLengthShortIntShortUint || c == kLengthLongIntLongUint ||
          c == kLengthLongDouble);
}

bool s21_is_specifier_prototype(char c) { return (c == kSpecifierPercent); }

bool s21_is_num(char c) { return (c >= '0' && c <= '9'); }

bool s21_is_passed_as_arg(char c) { return (c == '*'); }