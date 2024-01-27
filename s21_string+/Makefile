CC=gcc
FLAGS=-Werror -Wextra -Wall
CHECK_LIB_FLAGS=$(shell pkg-config --libs check)
MATH_LIB_FLAG=-lm
GCOVR_FLAGS=-fprofile-arcs -ftest-coverage

COMPILE_OBJECT_FILE_COMMAND=$(CC) -c $(FLAGS) 

TESTS_DIR=./tests
RUN_TESTS_COMMAND=$(TESTS_DIR)/s21_string_test


all: clean test s21_string.a gcov_report

clean:
	rm -f s21_string.a s21_string_test s21_string.html *.o $(TESTS_DIR)/s21_string_test

test: gcov_clean s21_string.a
	$(CC) $(FLAGS) -o $(TESTS_DIR)/s21_string_test \
		$(TESTS_DIR)/s21_string_test.c $(TESTS_DIR)/s21_memchr_test.c \
		$(TESTS_DIR)/s21_memcmp_test.c $(TESTS_DIR)/s21_strcspn_test.c $(TESTS_DIR)/s21_memcpy_test.c \
		$(TESTS_DIR)/s21_memset_test.c $(TESTS_DIR)/s21_strchr_test.c $(TESTS_DIR)/s21_strncat_test.c \
		$(TESTS_DIR)/s21_strncmp_test.c $(TESTS_DIR)/s21_strncpy_test.c $(TESTS_DIR)/s21_sprintf_test.c \
		$(TESTS_DIR)/s21_trim_test.c $(TESTS_DIR)/s21_to_upper_test.c $(TESTS_DIR)/s21_insert_test.c \
		$(TESTS_DIR)/s21_to_lower_test.c $(TESTS_DIR)/s21_strerror_test.c \
		$(TESTS_DIR)/s21_strlen_test.c $(TESTS_DIR)/s21_strpbrk_test.c \
		$(TESTS_DIR)/s21_strrchr_test.c $(TESTS_DIR)/s21_strstr_test.c $(TESTS_DIR)/s21_strtok_test.c \
		s21_string.a $(CHECK_LIB_FLAGS) $(GCOVR_FLAGS) $(MATH_LIB_FLAG)
	$(RUN_TESTS_COMMAND)

s21_string.a: clean s21_string.o common.o s21_sprintf.o
	ar -rc s21_string.a s21_string.o common.o s21_sprintf.o

s21_string.o: s21_string.c s21_string.h
	$(COMPILE_OBJECT_FILE_COMMAND) s21_string.c -o s21_string.o

common.o: common.c common.h s21_string.h
	$(COMPILE_OBJECT_FILE_COMMAND) common.c -o common.o

s21_sprintf.o: s21_sprintf.c s21_string.h common.h
	$(COMPILE_OBJECT_FILE_COMMAND) s21_sprintf.c -o s21_sprintf.o

gcov_report: test gcov_build

gcov_build: s21_string.a
	gcovr -r. --html -o s21_string.html

gcov_clean:
	rm -rf $(TESTS_DIR)/*.gcda $(TESTS_DIR)/*.gcno
