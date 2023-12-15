#define INIT_CAPACITY 2
#define INIT_LEN 0

#define CAPACITY_GROW 2

typedef struct dynamic_array_string {
  char **buffer;
  int cap;
  int len;
} dynamic_array_string_t;

dynamic_array_string_t *init_dynamic_array_string();
dynamic_array_string_t *append_string(
    dynamic_array_string_t *dynamic_string_array, char *str);
void dynamic_array_string_free(dynamic_array_string_t *dynamic_string_array);