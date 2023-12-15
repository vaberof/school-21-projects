#!/bin/bash

options=("-b" "-e" "-E" "-n" "-s" "-t" "-T" "--number" "--squeeze-blank" "--number-nonblank")
system_options=("-b" "-vE" "-E" "-n" "-s" "-vT" "-T" "--number" "--squeeze-blank" "--number-nonblank")

s21_cat_dir="../../cat"
test_filepath=("$s21_cat_dir/s21_cat.c")

cat_s21_command="$s21_cat_dir/s21_cat"
cat_system_command="cat"

s21_cat_make="make s21_cat -C $s21_cat_dir/"

$s21_cat_make

test_number=1

echo "TEST #$test_number without flags (s21_cat file and cat file)"
diff <(./$cat_s21_command $test_filepath) <($cat_system_command $test_filepath) -s
((test_number++))

for option_idx in ${!options[@]};do
  echo "TEST #$test_number with s21_cat flag ${options[$option_idx]} and cat flag ${system_options[$option_idx]}"
  diff <(./$cat_s21_command ${options[$option_idx]} $test_filepath) <($cat_system_command ${system_options[$option_idx]} $test_filepath) -s
  ((test_number++))
done
