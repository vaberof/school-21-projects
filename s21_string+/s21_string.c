#include "s21_string.h"

#ifndef STDLIB_H
#include <stdlib.h>

#endif /* STDLIB_H */

void *s21_memchr(const void *str, int c, size_t n) {
  const unsigned char *ptr = str;

  for (size_t i = 0; i < n && ptr != NULL; i++) {
    if (*ptr == c) {
      return (void *)(ptr);
    }
    ++ptr;
  }

  return NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *ptr1 = str1;
  const unsigned char *ptr2 = str2;

  for (size_t i = 0; i < (n - 1) && ptr1 != NULL && ptr2 != NULL; i++) {
    if (*ptr1 != *ptr2) {
      return *ptr1 - *ptr2;
    }

    ++ptr1;
    ++ptr2;
  }

  return *ptr1 - *ptr2;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *dest_ptr = dest;
  const unsigned char *src_ptr = src;

  for (size_t i = 0; i < n; i++) {
    *dest_ptr = *src_ptr;
    dest_ptr++;
    src_ptr++;
  }

  return dest;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *ptr = str;

  for (size_t i = 0; i < n && ptr != NULL; i++) {
    ptr[i] = c;
  }

  return str;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) {
    return dest;
  }

  char *dest_ptr = dest;
  const char *src_ptr = src;

  while (dest_ptr != NULL && *dest_ptr != '\0') {
    ++dest_ptr;
  }

  for (size_t i = 0; i < n; i++) {
    *dest_ptr = src_ptr[i];
    ++dest_ptr;
    if (src_ptr[i] == '\0') {
      return dest;
    }
  }

  *dest_ptr = '\0';

  return dest;
}

char *s21_strchr(const char *str, int c) {
  const char *ptr = str;

  while (ptr != NULL && *ptr != '\0') {
    if ((int)*ptr == c) {
      return (char *)ptr;
    }
    ++ptr;
  }

  return NULL;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  const char *ptr1 = str1;
  const char *ptr2 = str2;

  for (size_t i = 0; i < n && ptr1 != NULL && ptr2 != NULL; i++) {
    if (*ptr1 != *ptr2) {
      return *ptr1 - *ptr2;
    }
    ++ptr1;
    ++ptr2;
  }

  return 0;
}

size_t s21_strlen(const char *str) {
  size_t len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  if (dest == NULL || src == NULL) {
    return dest;
  }

  size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t i;
  for (i = 0; str1[i] != '\0'; i++) {
    for (size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        return i;
      }
    }
  }
  return i;
}

char *s21_strerror(int errnum) {
  char *err_array[] = err_arr;
  size_t Errors_length = sizeof(err_array) / sizeof(err_array[0]);
  if (errnum < 0 || errnum >= (int)Errors_length) {
    static char buf[50];
#ifdef __APPLE__
    s21_sprintf(buf, "Unknown error: %d", errnum);
#elif __linux__
    s21_sprintf(buf, "Unknown error %d", errnum);
#endif
    return buf;
  }
  return err_array[errnum];
}

void *s21_to_upper(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  size_t length = s21_strlen(str);
  char *buf = malloc(sizeof(char) * length + 1);

  for (size_t i = 0; i < length; i++) {
    int c = (int)str[i];
    if ((c > 96 && c < 123) || (c > 223 && c < 256)) {
      c = (int)str[i] - 32;
      buf[i] = (char)c;
    } else {
      buf[i] = str[i];
    }
  }

  buf[length] = '\0';

  return (void *)buf;
}

void *s21_to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  size_t length = s21_strlen(str);
  char *buf = malloc(sizeof(char) * length + 1);
  for (size_t i = 0; i < length; i++) {
    int c = (int)str[i];
    if ((c > 64 && c < 91) || (c > 191 && c < 224)) {
      c = (int)str[i] + 32;
      buf[i] = (char)c;
    } else {
      buf[i] = str[i];
    }
  }
  buf[length] = '\0';
  return (void *)buf;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (str == NULL || src == NULL || start_index > s21_strlen(src)) {
    return NULL;
  }

  size_t str_length = s21_strlen(str);
  size_t src_length = s21_strlen(src);
  size_t result_str_length = str_length + src_length;

  char *result_str = (char *)malloc(sizeof(char) * result_str_length + 1);
  if (result_str == NULL) {
    return NULL;
  }

  s21_strncpy(result_str, src, start_index);
  s21_strcpy(result_str + start_index, str);
  s21_strcpy(result_str + start_index + str_length, src + start_index);

  return (void *)result_str;
}

char *s21_strcpy(char *destination, const char *source) {
  // return if no memory is allocated to the destination
  if (destination == NULL) {
    return NULL;
  }

  // take a pointer pointing to the beginning of the destination string
  char *ptr = destination;

  // copy the C-string pointed by source into the array
  // pointed by destination
  while (*source != '\0') {
    *destination = *source;
    destination++;
    source++;
  }

  // include the terminating null character
  *destination = '\0';

  return ptr;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }
  size_t result_str_length = s21_strlen(src);
  size_t trim_chars_length = s21_strlen(trim_chars);
  char *result_str = malloc(sizeof(char) * result_str_length + 1);
  size_t new_str_index = 0;
  int isLastChars = 0;
  int isFirstChars = 1;
  for (size_t i = 0; i < result_str_length; i++) {
    int isMatch = 0;
    for (size_t j = 0; j < trim_chars_length; j++) {
      if (src[i] == trim_chars[j]) {
        isMatch = 1;
      }
    }
    if (isMatch == 1 && (isFirstChars == 1 || isLastChars == 1)) {
      continue;
    } else {
      isFirstChars = 0;
      isLastChars = 1;
      for (size_t j = i; j < result_str_length; j++) {
        int isMatch2 = 0;
        for (size_t k = 0; k < trim_chars_length; k++) {
          if (src[j] == trim_chars[k]) {
            isMatch2 = 1;
          }
        }
        if (isMatch2 == 0) {
          isLastChars = 0;
          break;
        }
      }
      if (isLastChars == 0) {
        result_str[new_str_index] = src[i];
        new_str_index++;
      }
    }
  }
  result_str[new_str_index] = '\0';

  return (void *)result_str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ptr1 = str1;
  const char *ptr2;

  while (*ptr1 != '\0') {
    ptr2 = str2;
    while (*ptr2 != '\0') {
      if (*ptr1 == *ptr2) {
        return (char *)ptr1;
      }
      ptr2++;
    }
    ptr1++;
  }

  return NULL;
}

char *s21_strrchr(const char *str, int c) {
  if (str == NULL) {
    return NULL;
  }

  const char *last_occurance = NULL;
  while (*str != '\0') {
    if ((int)*str == c) {
      last_occurance = str;
    }
    str++;
  }

  // We need this if c = 0
  if (c == 0 && *str == '\0') {
    last_occurance = str;
  }

  char *result = (char *)last_occurance;

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }

  while (*haystack != '\0') {
    char *h = (char *)haystack;
    char *n = (char *)needle;

    while (*h == *n && *n != '\0') {
      h++;
      n++;
    }

    if (*n == '\0') {
      return (char *)haystack;
    }

    haystack++;
  }

  return NULL;
}

unsigned int is_delim(char c, const char *delim) {
  while (*delim != '\0') {
    if (c == *delim) return 1;
    delim++;
  }
  return 0;
}
char *s21_strtok(char *str, const char *delim) {
  static char *backup_string;  // start of the next search
  if (!str) {
    str = backup_string;
  }
  if (!str) {
    // user is bad user
    return NULL;
  }
  // handle beginning of the string containing delims
  while (1) {
    if (is_delim(*str, delim)) {
      str++;
      continue;
    }
    if (*str == '\0') {
      // we've reached the end of the string
      return NULL;
    }
    break;
  }
  char *ret = str;
  while (1) {
    if (*str == '\0') {
      /*end of the input string and
      next exec will return NULL*/
      backup_string = str;
      return ret;
    }
    if (is_delim(*str, delim)) {
      *str = '\0';
      backup_string = str + 1;
      return ret;
    }
    str++;
  }
}