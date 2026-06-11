#!/bin/bash

# ANSI color codes (\033 == ESC)
readonly C_GREEN='\033[32m'
readonly C_RED='\033[31m'
readonly C_RESET='\033[0m'

# Compile your program if necessary
# g++ xxx.cpp -o test.o

# Numeric-friendly order (1, 2, ..., 10) instead of lexicographic (1, 10, 2, ...)
shopt -s nullglob
while IFS= read -r input_file; do
    [[ -n $input_file ]] || continue
    # Get the base filename without the extension
    base_name=$(basename "$input_file" .in)
    expected_output="test_cases/$base_name.out"

    # Run the program and capture output
    # You can store it in a temporary file or a variable
    actual_output=$(./test.o < "$input_file")

    # Compare with expected output
    if diff -w <(echo "$actual_output") "$expected_output" > /dev/null; then
        echo -e "${C_GREEN}Test $base_name: PASSED${C_RESET}"
    else
        echo -e "${C_RED}Test $base_name: FAILED${C_RESET}"
        # echo "Expected vs Actual:"
        # diff -w "$expected_output" <(echo "$actual_output")
    fi
done < <(printf '%s\n' test_cases/*.in | sort -V)
