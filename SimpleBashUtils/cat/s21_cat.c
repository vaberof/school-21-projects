#include "s21_cat.h"

#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/common.h"

const char SHORT_OPTIONS[] = "beEnstT";

const struct option LONG_OPTIONS[] = {
    {"number-nonblank", OPTION_HAS_NO_ARGUMENT, NULL, 'b'},
    {"number", OPTION_HAS_NO_ARGUMENT, NULL, 'n'},
    {"squeeze-blank", OPTION_HAS_NO_ARGUMENT, NULL, 's'},
};

int main(int argc, char **argv) {
  Options options = {0};

  if (parse_options(argc, argv, &options) != CODE_SUCCESS) {
    return CODE_ERROR;
  }

  if (parse_files(argc - optind, optind, argv, &options) != CODE_SUCCESS) {
    return CODE_ERROR;
  }

  return CODE_SUCCESS;
}

int parse_options(int argc, char **argv, Options *options) {
  char option;
  int long_option_index = 0;

  while ((option = getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS,
                               &long_option_index)) != GETOPT_LONG_NO_OPTIONS) {
    if (process_options(option, options) != CODE_SUCCESS) {
      return CODE_ERROR;
    }
  }

  if (options->b) {
    // option -b overrides -n
    options->n = false;
  }

  return CODE_SUCCESS;
}

int process_options(char option, Options *options) {
  switch (option) {
    case 'b':
      options->b = true;
      break;
    case 'e':
      options->e = true;
      break;
    case 'E':
      options->E = true;
      break;
    case 'n':
      options->n = true;
      break;
    case 's':
      options->s = true;
      break;
    case 't':
      options->t = true;
      break;
    case 'T':
      options->T = true;
      break;
    default:
      fprintf(stderr, "%s\n", "unkown option");
      return CODE_ERROR;
  }
  return CODE_SUCCESS;
}

int parse_files(int files_count, int file_arg_index, char **argv,
                Options *options) {
  if (files_count == 0) {
    fprintf(stderr, "%s\n", "need to provide at least one filepath");
    return CODE_ERROR;
  }
  process_files(files_count, file_arg_index, argv, options);
  return CODE_SUCCESS;
}

void process_files(int files_count, int file_arg_index, char **argv,
                   Options *options) {
  int nonempty_lines_count = 1;
  int all_lines_count = 1;
  int empty_lines_count = 1;

  while (files_count > 0) {
    char *filepath = argv[file_arg_index];

    FILE *file_ptr = open_file(filepath, READ_MODE);
    if (file_ptr == NULL) {
      fprintf(stderr, "s21_cat: %s: No such file or directory\n", filepath);
      --files_count;
      ++file_arg_index;
      continue;
    }

    process_file(file_ptr, &nonempty_lines_count, &all_lines_count,
                 &empty_lines_count, options);

    --files_count;
    ++file_arg_index;

    if (file_ptr) {
      fclose(file_ptr);
    }
  }
}

void process_file(FILE *file_ptr, int *nonempty_lines_count,
                  int *all_lines_count, int *empty_lines_count,
                  Options *options) {
  char prev_symbol = '\n';
  char curr_symbol = getc(file_ptr);

  while (!feof(file_ptr)) {
    if (options->s) {
      count_empty_lines(curr_symbol, empty_lines_count);
    }

    if ((*empty_lines_count) > 2) {
      prev_symbol = curr_symbol;
      curr_symbol = getc(file_ptr);
      continue;
    }

    number_lines(curr_symbol, prev_symbol, nonempty_lines_count,
                 all_lines_count, options);
    print_symbol(curr_symbol, options);

    prev_symbol = curr_symbol;
    curr_symbol = getc(file_ptr);
  }
}

void count_empty_lines(char curr_symbol, int *empty_lines_count) {
  if (curr_symbol == '\n') {
    (*empty_lines_count)++;
  } else {
    (*empty_lines_count) = 0;
  }
}

void number_lines(char curr_symbol, char prev_symbol, int *nonempty_lines_count,
                  int *all_lines_count, Options *options) {
  if (options->b) {
    number_nonempty_lines(curr_symbol, prev_symbol, nonempty_lines_count);
  } else if (options->n) {
    number_all_lines(prev_symbol, all_lines_count);
  }
}

void number_nonempty_lines(char curr_symbol, char prev_symbol,
                           int *nonempty_lines_count) {
  if (prev_symbol == '\n' && curr_symbol != '\n') {
    fprintf(stdout, "%*d\t", PRINT_INDENT_WIDTH, (*nonempty_lines_count));
    (*nonempty_lines_count)++;
  }
}

void number_all_lines(char prev_symbol, int *all_lines_count) {
  if (prev_symbol == '\n') {
    fprintf(stdout, "%*d\t", PRINT_INDENT_WIDTH, (*all_lines_count));
    (*all_lines_count)++;
  }
}

void print_symbol(char symbol, Options *options) {
  if (symbol == '\n') {
    print_end_line(symbol, options);
  } else if (symbol == '\t') {
    print_tab(symbol, options);
  } else if ((options->e || options->t) && iscntrl(symbol)) {
    print_cntrl(symbol);
  } else if ((options->e || options->t) && ismeta(symbol)) {
    print_meta(symbol);
  } else {
    fprintf(stdout, "%c", symbol);
  }
}

void print_end_line(char symbol, Options *options) {
  if (options->e || options->E) {
    fprintf(stdout, "%c", '$');
    fprintf(stdout, "%c", symbol);
  } else {
    fprintf(stdout, "%c", symbol);
  }
}

void print_tab(char symbol, Options *options) {
  if (options->t || options->T) {
    fprintf(stdout, "%c%c", '^', 'I');
  } else {
    fprintf(stdout, "%c", symbol);
  }
}

void print_cntrl(char symbol) {
  fprintf(stdout, "^%c", symbol + NONPRINTING_SYMBOL_SHIFT);
}

void print_meta(char symbol) {
  fprintf(stdout, "M-%c", symbol - META_SYMBOL_SHIFT);
}

bool ismeta(char symbol) {
  return ((unsigned char)symbol > ASCII_DELETE_SYMBOL);
}
