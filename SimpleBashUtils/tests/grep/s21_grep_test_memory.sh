#!/bin/bash

valgrind="valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --error-exitcode=1 -q"

s21_grep_dir="../../grep"
test_filepath=("$s21_grep_dir/s21_grep.c")

grep_pattern="int"
grep_patterns_filepath="./patterns.txt"

options=("i" "v" "c" "l" "n" "h" "s" "o")

grep_s21_command="$s21_grep_dir/s21_grep"
grep_system_command="grep"

s21_grep_make="make s21_grep -C $s21_grep_dir/"

$s21_grep_make

test_number=1

for option_idx in ${!options[@]};do
  valgrind_result="$($valgrind ./$grep_s21_command $grep_pattern -${options[$option_idx]} $test_filepath)"
  if [[ $? -eq 1 ]];then
    echo "TEST #$test_number: LEAKS DETECTED WITH FLAG ${options[$option_idx]}"
    echo "$valgrind_result"
  else
    echo "TEST #$test_number: NO LEAKS WITH FLAG ${options[$option_idx]}"
  fi
  ((test_number++))
done

# Тесты с парными комбинациями (-iv, -ic...)
for option_idx in ${!options[@]};do
    for option_idx2 in ${!options[@]};do        
        if [ "${options[$option_idx]}" != "${options[$option_idx2]}" ];then
            valgrind_result="$($valgrind ./$grep_s21_command $grep_pattern -${options[$option_idx]}${options[$option_idx2]} $test_filepath)"
            if [[ $? -eq 1 ]];then
                echo "TEST #$test_number: LEAKS DETECTED WITH FLAGS -${options[$option_idx]}${options[$option_idx2]}"
                echo "$valgrind_result"
            else
                echo "TEST #$test_number: NO LEAKS WITH FLAGS -${options[$option_idx]}${options[$option_idx2]}"
            fi
            ((test_number++))
        fi        
    done
done
