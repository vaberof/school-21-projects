#include <regex.h>
#include <stdbool.h>
#include <stdio.h>

#include "../data_structures/dynamic_array_string/dynamic_array_string.h"

#define GET_LINE_EOF -1

#define REGEX_ERROR_MSG_BUF_SIZE 128

#define MIN_ARGC 2

typedef struct Options {
  bool e;
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
  bool o;
} Options;

int parse_options(int argc, char **argv, dynamic_array_string_t *patterns,
                  Options *options);
int process_options(char option, dynamic_array_string_t *patterns,
                    Options *options);

void override_options(Options *options);

dynamic_array_string_t *add_pattern(dynamic_array_string_t *patterns,
                                    char *pattern);
dynamic_array_string_t *add_patterns_from_file(dynamic_array_string_t *patterns,
                                               char *filepath,
                                               Options *options);

int parse_files(int files_count, int file_arg_index, char **argv,
                dynamic_array_string_t *patterns, Options *options);

dynamic_array_string_t *get_filepaths(int files_count, int file_arg_index,
                                      char **argv,
                                      dynamic_array_string_t *filepaths);

int process_files(dynamic_array_string_t *filepaths,
                  dynamic_array_string_t *patterns, Options *options);

int process_file(FILE *file_ptr, char *filepath, int files_count,
                 dynamic_array_string_t *patterns, Options *options);

void print_last_file_line(char *filepath, int files_count, bool has_unmatched,
                          bool has_matched, int matched_lines_count,
                          int lines_count, Options *options);

bool match_patterns(char *source_string, bool *has_unmatched,
                    dynamic_array_string_t *patterns, char *filepath,
                    int files_count, int *matched_lines_count, int *line_count,
                    Options *options);
char *match_pattern(char *source_string, char *pattern, regmatch_t *pmatch,
                    Options *options);

void print_all_matched_parts(char *source_string, char *pattern,
                             regmatch_t *pmatch, char *filepath,
                             int files_count, int *lines_count,
                             Options *options);

void print_matched_part(char *source_string, char *filepath, int files_count,
                        int *lines_count, Options *options);

void print_matched_line(char *matched_line, int *lines_count, char *filepath,
                        int files_count, Options *options);

void print_unmatched_line(char *source_string, int *lines_count, char *filepath,
                          int files_count, bool has_matched,
                          bool *has_unmatched, Options *options);

void print_nonmatched_line(char *source_line, char *matched_line,
                           int *lines_count, char *filepath, int files_count,
                           Options *options);

bool has_newline_symbol(char *line);

void print_line(char *matched_line, Options *options);
void print_total_matched_lines_count(int matched_lines_count, int lines_count,
                                     Options *options);
void print_matched_filepath(char *filepath, int files_count, Options *options);
void print_line_number(int line_count, Options *options);
void print_file_error(char *filepath, Options *options);
