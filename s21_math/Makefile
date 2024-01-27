CC=gcc
FLAGS=-Werror -Wextra -Wall
CHECK_LIB_FLAGS=$(shell pkg-config --libs check)
MATH_LIB_FLAG=-lm
GCOVR_FLAGS=-fprofile-arcs -ftest-coverage

COMPILE_OBJECT_FILE_COMMAND=$(CC) -c $(FLAGS) 

TESTS_DIR=./tests
RUN_TESTS_COMMAND=$(TESTS_DIR)/s21_math_test


all: clean test s21_math.a gcov_report

clean:
	rm -f s21_math.a s21_math_test s21_math.html *.o $(TESTS_DIR)/s21_math_test

test: gcov_clean s21_math.a
	$(CC) $(FLAGS) -o $(TESTS_DIR)/s21_math_test \
		$(TESTS_DIR)/s21_math_test.c $(TESTS_DIR)/s21_log_test.c \
		$(TESTS_DIR)/s21_exp_test.c $(TESTS_DIR)/s21_pow_test.c \
		$(TESTS_DIR)/s21_sin_test.c $(TESTS_DIR)/s21_sqrt_test.c \
		$(TESTS_DIR)/s21_fmod_test.c $(TESTS_DIR)/s21_floor_test.c \
		$(TESTS_DIR)/s21_ceil_test.c $(TESTS_DIR)/s21_fabs_test.c \
		$(TESTS_DIR)/s21_cos_test.c $(TESTS_DIR)/s21_abs_test.c \
		$(TESTS_DIR)/s21_acos_test.c $(TESTS_DIR)/s21_atan_test.c \
		$(TESTS_DIR)/s21_asin_test.c $(TESTS_DIR)/s21_tan_test.c \
		s21_math.a $(CHECK_LIB_FLAGS) $(GCOVR_FLAGS) $(MATH_LIB_FLAG)
	$(RUN_TESTS_COMMAND)

s21_math.a: clean s21_math.o 
	ar -rc s21_math.a s21_math.o 

s21_math.o: s21_math.c s21_math.h
	$(COMPILE_OBJECT_FILE_COMMAND) s21_math.c -o s21_math.o

gcov_report: test gcov_build

gcov_build: s21_math.a
	gcovr -r. --html -o s21_math.html

gcov_clean:
	rm -rf $(TESTS_DIR)/*.gcda $(TESTS_DIR)/*.gcno
