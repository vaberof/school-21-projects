#!/bin/bash

s21_grep_dir="../../grep"
test_filepath=("$s21_grep_dir/s21_grep.c")

grep_pattern="int"
grep_patterns_filepath="./patterns.txt"

options=("i" "v" "c" "l" "n" "h" "s" "o")
options_with_args=("-e $grep_pattern" "-f $grep_patterns_filepath")

grep_s21_command="$s21_grep_dir/s21_grep"
grep_system_command="grep"

s21_grep_make="make s21_grep -C $s21_grep_dir/"

$s21_grep_make

test_number=1

# Тест без флагов (s21_grep pattern file)
echo "TEST #$test_number without flags (s21_grep file and grep file)"
diff <(./$grep_s21_command $grep_pattern $test_filepath) <($grep_system_command $grep_pattern $test_filepath) -s
((test_number++))

# Тесты с флагами -e и -f
for option in "${options_with_args[@]}"; do
  echo "TEST #$test_number with s21_grep flag '$option' and grep flag '$option'"
  diff <(./$grep_s21_command $option $test_filepath) <($grep_system_command $option $test_filepath) -s
  ((test_number++))
done

# Тесты с одним флагом (-i, -v...)
for option_idx in ${!options[@]};do
  echo "TEST #$test_number with s21_grep flag '-${options[$option_idx]}' and grep flag '-${options[$option_idx]}'"
  diff <(./$grep_s21_command $grep_pattern -${options[$option_idx]} $test_filepath) <($grep_system_command $grep_pattern -${options[$option_idx]} $test_filepath) -s
  ((test_number++))
done

# Тесты с парными комбинациями (-iv, -ic...)
for option_idx in ${!options[@]};do
    for option_idx2 in ${!options[@]};do        
        if [ "${options[$option_idx]}" != "${options[$option_idx2]}" ];then
          echo "TEST #$test_number with s21_grep flags combination '-${options[$option_idx]}${options[$option_idx2]}' and grep flags combination '-${options[$option_idx]}${options[$option_idx2]}'"
          diff <(./$grep_s21_command $grep_pattern -${options[$option_idx]}${options[$option_idx2]} $test_filepath) <($grep_system_command $grep_pattern -${options[$option_idx]}${options[$option_idx2]} $test_filepath) -s
          ((test_number++)) 
        fi        
    done
done
