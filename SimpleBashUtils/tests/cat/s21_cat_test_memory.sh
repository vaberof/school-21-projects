#!/bin/bash

valgrind="valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q"

options=("-b" "-e" "-E" "-n" "-s" "-t" "-T" "--number" "--squeeze-blank" "--number-nonblank")

s21_cat_dir="../../cat"
test_filepath=("$s21_cat_dir/s21_cat.c")

cat_s21_command="$s21_cat_dir/s21_cat"
cat_system_command="cat"

s21_cat_make="make s21_cat -C $s21_cat_dir/"

$s21_cat_make

test_number=1

for option_idx in ${!options[@]};do
  valgrind_result="$($valgrind ./$cat_s21_command ${options[$option_idx]} $test_filepath)"
  if [[ $? -eq 1 ]];then
    echo "TEST #$test_number: LEAKS DETECTED WITH FLAG ${options[$option_idx]}"
    echo "$valgrind_result"
  else
    echo "TEST #$test_number: NO LEAKS WITH FLAG ${options[$option_idx]}"
  fi
  ((test_number++))
done
