CC=gcc
FLAGS=-Werror -Wextra -Wall

COMMON_DIR=../common
DATA_STRUCTURES_DIR=../data_structures
DYNAMIC_ARRAY_STRING_DIR=$(DATA_STRUCTURES_DIR)/dynamic_array_string

s21_grep: clean
	$(CC) $(FLAGS) $(COMMON_DIR)/common.c $(DYNAMIC_ARRAY_STRING_DIR)/dynamic_array_string.c s21_grep.c -o s21_grep

clean:
	rm -f s21_grep
