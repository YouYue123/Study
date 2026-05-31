#!/bin/bash

# Compile your program if necessary
# g++ xxx.cpp -o test.o

for input_file in test_cases/*.in; do
    # Get the base filename without the extension
    base_name=$(basename "$input_file" .in)
    expected_output="test_cases/$base_name.out"

    # Run the program and capture output
    # You can store it in a temporary file or a variable
    actual_output=$(./test.o < "$input_file")

    # Compare with expected output
    if diff -w <(echo "$actual_output") "$expected_output" > /dev/null; then
        echo "Test $base_name: PASSED"
    else
        echo "Test $base_name: FAILED"
        echo "Expected vs Actual:"
        diff -w "$expected_output" <(echo "$actual_output")
    fi
done