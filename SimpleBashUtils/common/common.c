#include "common.h"

FILE *open_file(char *filepath, char *mode) {
  FILE *file_ptr;
  file_ptr = fopen(filepath, mode);
  return file_ptr;
}