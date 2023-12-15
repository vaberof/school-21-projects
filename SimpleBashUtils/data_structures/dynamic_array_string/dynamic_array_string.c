#ifndef DYNAMIC_ARRAY_STRING_H
#include "dynamic_array_string.h"
#endif

#include <stdlib.h>
#include <string.h>

dynamic_array_string_t *init_dynamic_array_string() {
  dynamic_array_string_t *dynamic_array_string =
      malloc(sizeof(dynamic_array_string_t));
  dynamic_array_string->buffer = malloc(INIT_CAPACITY * sizeof(char *));
  dynamic_array_string->cap = INIT_CAPACITY;
  dynamic_array_string->len = INIT_LEN;
  return dynamic_array_string;
}

dynamic_array_string_t *append_string(
    dynamic_array_string_t *dynamic_array_string, char *str) {
  int new_len = dynamic_array_string->len + 1;
  char *string_copy = strdup(str);

  if (new_len > dynamic_array_string->cap) {
    int new_cap = dynamic_array_string->cap * CAPACITY_GROW;
    char **new_buffer =
        realloc(dynamic_array_string->buffer, new_cap * sizeof(char *));

    dynamic_array_string->buffer = new_buffer;
    dynamic_array_string->buffer[dynamic_array_string->len] = string_copy;
    dynamic_array_string->cap = new_cap;
    dynamic_array_string->len = new_len;
  } else {
    dynamic_array_string->buffer[dynamic_array_string->len] = string_copy;
    dynamic_array_string->len = new_len;
  }

  return dynamic_array_string;
}

void dynamic_array_string_free(dynamic_array_string_t *dynamic_array_string) {
  for (int i = 0; i < dynamic_array_string->len; i++) {
    free(dynamic_array_string->buffer[i]);
  }
  free(dynamic_array_string->buffer);
  free(dynamic_array_string);
}
