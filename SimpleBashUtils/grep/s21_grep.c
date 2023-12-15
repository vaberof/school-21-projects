#include "s21_grep.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/common.h"

const char SHORT_OPTIONS[] = "e:ivclnhsf:o";

const struct option LONG_OPTIONS[] = {
    {0, 0, 0, 0},
};

int main(int argc, char **argv) {
  if (argc < MIN_ARGC) {
    fprintf(stderr, "%s\n", "not enough arguments");
    return CODE_ERROR;
  }

  Options options = {0};

  dynamic_array_string_t *patterns = init_dynamic_array_string();

  if (parse_options(argc, argv, patterns, &options) != CODE_SUCCESS) {
    dynamic_array_string_free(patterns);
    return CODE_ERROR;
  }

  parse_files(argc - optind, optind, argv, patterns, &options);

  dynamic_array_string_free(patterns);
  return CODE_SUCCESS;
}

int parse_options(int argc, char **argv, dynamic_array_string_t *patterns,
                  Options *options) {
  char option;
  int long_option_index = 0;

  while ((option = getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS,
                               &long_option_index)) != GETOPT_LONG_NO_OPTIONS) {
    if (process_options(option, patterns, options) != CODE_SUCCESS) {
      return CODE_ERROR;
    }
  }

  override_options(options);

  if (!options->e && !options->f && argc >= MIN_ARGC) {
    // if there are no option "-e" with pattern or "-f" with file of patterns,
    // then first non-option argument is pattern
    patterns = add_pattern(patterns, argv[optind]);
    ++optind;
  }
  return CODE_SUCCESS;
}

int process_options(char option, dynamic_array_string_t *patterns,
                    Options *options) {
  switch (option) {
    case 'e':
      options->e = true;
      patterns = add_pattern(patterns, optarg);
      break;
    case 'i':
      options->i = true;
      break;
    case 'v':
      options->v = true;
      break;
    case 'c':
      options->c = true;
      break;
    case 'l':
      options->l = true;
      break;
    case 'n':
      options->n = true;
      break;
    case 'h':
      options->h = true;
      break;
    case 's':
      options->s = true;
      break;
    case 'f':
      options->f = true;
      patterns = add_patterns_from_file(patterns, optarg, options);
      break;
    case 'o':
      options->o = true;
      break;
    default:
      fprintf(stderr, "%s", "unkown option\n");
      return CODE_ERROR;
  }
  return CODE_SUCCESS;
}

void override_options(Options *options) {
  if (options->l) {
    // option l overrides v, c, n, o, h
    options->v = false;
    options->c = false;
    options->n = false;
    options->o = false;
    options->h = false;
  } else if (options->c) {
    // option c overrides n, o
    options->n = false;
    options->o = false;
  }
}

dynamic_array_string_t *add_pattern(dynamic_array_string_t *patterns,
                                    char *pattern) {
  bool is_unique_pattern = true;

  for (int i = 0; i < patterns->len; i++) {
    if (strcmp(patterns->buffer[i], pattern) == 0) {
      is_unique_pattern = false;
      break;
    }
  }

  if (is_unique_pattern) {
    return append_string(patterns, pattern);
  }

  return patterns;
}

dynamic_array_string_t *add_patterns_from_file(dynamic_array_string_t *patterns,
                                               char *filepath,
                                               Options *options) {
  FILE *file_ptr = open_file(filepath, READ_MODE);
  if (file_ptr == NULL) {
    print_file_error(filepath, options);
    return patterns;
  }

  char *line_buf = NULL;
  size_t line_buf_size = 0;

  size_t line_len = 0;

  while (getline(&line_buf, &line_buf_size, file_ptr) != GET_LINE_EOF) {
    line_len = strlen(line_buf);

    if (line_buf[line_len - 1] == '\n') {
      line_buf[line_len - 1] = '\0';
    }

    patterns = add_pattern(patterns, line_buf);
  }

  fclose(file_ptr);

  if (line_buf) {
    free(line_buf);
  }

  return patterns;
}

int parse_files(int files_count, int file_arg_index, char **argv,
                dynamic_array_string_t *patterns, Options *options) {
  if (files_count == 0) {
    fprintf(stderr, "%s", "need to provide at least one filepath\n");
    return CODE_ERROR;
  }

  dynamic_array_string_t *filepaths = init_dynamic_array_string();

  filepaths = get_filepaths(files_count, file_arg_index, argv, filepaths);

  process_files(filepaths, patterns, options);

  dynamic_array_string_free(filepaths);
  return CODE_SUCCESS;
}

dynamic_array_string_t *get_filepaths(int files_count, int file_arg_index,
                                      char **argv,
                                      dynamic_array_string_t *filepaths) {
  while (files_count > 0) {
    char *filepath = argv[file_arg_index];
    filepaths = append_string(filepaths, filepath);
    --files_count;
    ++file_arg_index;
  }

  return filepaths;
}

int process_files(dynamic_array_string_t *filepaths,
                  dynamic_array_string_t *patterns, Options *options) {
  int error = 0;

  int files_count = filepaths->len;

  for (int i = 0; i < filepaths->len; i++) {
    char *filepath = filepaths->buffer[i];

    FILE *file_ptr = open_file(filepath, READ_MODE);
    if (file_ptr == NULL) {
      print_file_error(filepath, options);
      continue;
    }

    error = process_file(file_ptr, filepath, files_count, patterns, options);
    if (error != CODE_SUCCESS) {
      return error;
    }

    if (file_ptr) {
      fclose(file_ptr);
    }
  }

  return CODE_SUCCESS;
}

int process_file(FILE *file_ptr, char *filepath, int files_count,
                 dynamic_array_string_t *patterns, Options *options) {
  char *line_buf = NULL;
  size_t line_buf_size = 0;

  int matched_lines_count = 0;
  int lines_count = 0;

  bool has_matched = false;
  bool has_unmatched = false;
  bool match_result = false;

  while (getline(&line_buf, &line_buf_size, file_ptr) != GET_LINE_EOF) {
    ++lines_count;

    match_result = match_patterns(line_buf, &has_unmatched, patterns, filepath,
                                  files_count, &matched_lines_count,
                                  &lines_count, options);
    if (match_result) {
      has_matched = true;
    }
  }

  print_last_file_line(filepath, files_count, has_unmatched, has_matched,
                       matched_lines_count, lines_count, options);

  if (line_buf) {
    free(line_buf);
  }

  return CODE_SUCCESS;
}

bool match_patterns(char *source_string, bool *has_unmatched,
                    dynamic_array_string_t *patterns, char *filepath,
                    int files_count, int *matched_lines_count, int *lines_count,
                    Options *options) {
  char *match_result = NULL;
  char *last_matched_line = NULL;
  bool has_matched = false;

  regmatch_t pmatch[strlen(source_string)];

  for (int i = 0; i < patterns->len; i++) {
    char *pattern = patterns->buffer[i];

    match_result = match_pattern(source_string, pattern, pmatch, options);
    if (match_result != NULL) {
      has_matched = true;
    }

    if (!options->v && match_result != NULL) {
      has_matched = true;
      last_matched_line = match_result;
    }

    if (options->o && match_result != NULL) {
      print_all_matched_parts(source_string, pattern, pmatch, filepath,
                              files_count, lines_count, options);
    }
  }

  print_unmatched_line(source_string, lines_count, filepath, files_count,
                       has_matched, has_unmatched, options);

  if (has_matched) {
    print_matched_line(last_matched_line, lines_count, filepath, files_count,
                       options);
    (*matched_lines_count)++;
  }

  return has_matched;
}

char *match_pattern(char *source_string, char *pattern, regmatch_t *pmatch,
                    Options *options) {
  int source_string_len = strlen(source_string);

  char *match_result = NULL;
  char reg_error_msg_buf[REGEX_ERROR_MSG_BUF_SIZE];

  regex_t regex;
  int error = CODE_SUCCESS;

  if (options->i) {
    error = regcomp(&regex, pattern, 0 | REG_ICASE);
  } else {
    error = regcomp(&regex, pattern, 0);
  }

  error = regexec(&regex, source_string, source_string_len, pmatch, 0);
  if (!error) {
    match_result = source_string;
  } else if (error != REG_NOMATCH) {
    regerror(error, &regex, reg_error_msg_buf, sizeof(reg_error_msg_buf));
    fprintf(stderr, "Regex match failed: %s\n", reg_error_msg_buf);
    regfree(&regex);
    exit(CODE_ERROR);
  }

  regfree(&regex);

  return match_result;
}

void print_all_matched_parts(char *source_string, char *pattern,
                             regmatch_t *pmatch, char *filepath,
                             int files_count, int *lines_count,
                             Options *options) {
  bool has_matched = true;
  char *match_result = NULL;

  char *matched_part = malloc(sizeof(char) * strlen(source_string) + 1);
  int matched_part_len = 0;

  while (source_string != NULL && has_matched) {
    match_result = match_pattern(source_string, pattern, pmatch, options);
    if (match_result == NULL) {
      has_matched = false;
    } else {
      matched_part_len = pmatch[0].rm_eo - pmatch[0].rm_so;
      memcpy(matched_part, source_string + pmatch[0].rm_so, matched_part_len);
      matched_part[matched_part_len] = '\0';
      print_matched_part(matched_part, filepath, files_count, lines_count,
                         options);
    }
    source_string += pmatch[0].rm_so + 1;
  }
  free(matched_part);
}

void print_matched_part(char *matched_part, char *filepath, int files_count,
                        int *lines_count, Options *options) {
  if (!options->v && options->o) {
    print_matched_filepath(filepath, files_count, options);
    print_line_number(*lines_count, options);
    print_line(matched_part, options);
  }
}

void print_matched_line(char *matched_line, int *lines_count, char *filepath,
                        int files_count, Options *options) {
  if (!options->v && !options->o && !options->l && !options->c) {
    print_matched_filepath(filepath, files_count, options);
    print_line_number(*lines_count, options);
    print_line(matched_line, options);
  }
}

void print_unmatched_line(char *source_string, int *lines_count, char *filepath,
                          int files_count, bool has_matched,
                          bool *has_unmatched, Options *options) {
  if (!options->o && !options->l && !options->c && options->v && !has_matched) {
    (*has_unmatched) = true;
    print_matched_filepath(filepath, files_count, options);
    print_line_number(*lines_count, options);
    print_line(source_string, options);
  }
}

void print_line(char *matched_line, Options *options) {
  if (!options->c) {
    if (has_newline_symbol(matched_line)) {
      fprintf(stdout, "%s", matched_line);
    } else {
      fprintf(stdout, "%s\n", matched_line);
    }
  }
}

void print_last_file_line(char *filepath, int files_count, bool has_unmatched,
                          bool has_matched, int matched_lines_count,
                          int lines_count, Options *options) {
  if (options->l && options->v && has_unmatched) {
    print_matched_filepath(filepath, files_count, options);
    print_total_matched_lines_count(matched_lines_count, lines_count, options);
  } else if (options->l && !options->v && has_matched) {
    print_matched_filepath(filepath, files_count, options);
    print_total_matched_lines_count(matched_lines_count, lines_count, options);
  } else if (options->c) {
    print_matched_filepath(filepath, files_count, options);
    print_total_matched_lines_count(matched_lines_count, lines_count, options);
  }
}

void print_matched_filepath(char *filepath, int files_count, Options *options) {
  if (!options->h && options->l) {
    fprintf(stdout, "%s\n", filepath);
  } else if (!options->h && files_count > 1) {
    fprintf(stdout, "%s:", filepath);
  }
}

void print_total_matched_lines_count(int matched_lines_count, int lines_count,
                                     Options *options) {
  if (!options->l && options->c && options->v) {
    fprintf(stdout, "%d\n", lines_count - matched_lines_count);
  } else if (!options->l && options->c) {
    fprintf(stdout, "%d\n", matched_lines_count);
  }
}

void print_line_number(int lines_count, Options *options) {
  if (options->n) {
    fprintf(stdout, "%d:", lines_count);
  }
}

void print_file_error(char *filepath, Options *options) {
  if (!options->s) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", filepath);
  }
}

bool has_newline_symbol(char *str) {
  char *pos = strchr(str, '\n');
  return pos != NULL;
}