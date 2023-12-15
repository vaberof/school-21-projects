#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define OPTION_HAS_NO_ARGUMENT 0

#define PRINT_INDENT_WIDTH 6

#define ASCII_DELETE_SYMBOL 127

#define NONPRINTING_SYMBOL_SHIFT 64
#define META_SYMBOL_SHIFT 128

typedef struct Options {
  bool b;
  bool e;
  bool E;
  bool n;
  bool s;
  bool t;
  bool T;
} Options;

int parse_options(int argc, char **argv, Options *options);
int process_options(char option, Options *options);

int parse_files(int files_count, int file_arg_index, char **argv,
                Options *options);
void process_files(int files_count, int file_arg_index, char **argv,
                   Options *options);
void process_file(FILE *file_ptr, int *nonblank_line_count, int *all_line_count,
                  int *empty_lines_count, Options *options);

void number_lines(char curr_symbol, char prev_symbol, int *nonempty_lines_count,
                  int *all_lines_count, Options *options);
void number_nonempty_lines(char curr_symbol, char prev_symbol,
                           int *nonblank_line_count);
void number_all_lines(char prev_symbol, int *all_line_count);

void count_empty_lines(char curr_symbol, int *empty_lines_count);

void print_symbol(char symbol, Options *options);
void print_end_line(char symbol, Options *options);
void print_tab(char symbol, Options *options);
void print_cntrl(char symbol);
void print_meta(char symbol);
bool ismeta(char symbol);