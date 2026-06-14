#!/bin/bash

# ANSI color codes (\033 == ESC)
readonly C_GREEN='\033[32m'
readonly C_RED='\033[31m'
readonly C_YELLOW='\033[33m'
readonly C_RESET='\033[0m'

# Per-test CPU wall time (GNU coreutils `timeout` / Homebrew `gtimeout`)
readonly TIME_LIMIT_SEC=1

pick_timeout_bin() {
    if command -v timeout >/dev/null 2>&1; then
        printf '%s\n' timeout
    elif command -v gtimeout >/dev/null 2>&1; then
        printf '%s\n' gtimeout
    else
        printf '%s\n' ''
    fi
}
TIMEOUT_BIN=$(pick_timeout_bin)
readonly TIMEOUT_BIN

# Compile your program if necessary
# g++ xxx.cpp -o test.o

# Numeric-friendly order (1, 2, ..., 10) instead of lexicographic (1, 10, 2, ...)
shopt -s nullglob
if [[ -z $TIMEOUT_BIN ]]; then
    echo -e "${C_YELLOW}Warning: no timeout/gtimeout; install coreutils or run without time limit${C_RESET}" >&2
fi
while IFS= read -r input_file; do
    [[ -n $input_file ]] || continue
    # Get the base filename without the extension
    base_name=$(basename "$input_file" .in)
    expected_output="test_cases/$base_name.out"

    # Run the program and capture output (stdout only), with time limit
    if [[ -n $TIMEOUT_BIN ]]; then
        actual_output=$("$TIMEOUT_BIN" "$TIME_LIMIT_SEC" ./test.o < "$input_file")
        run_status=$?
    else
        actual_output=$(./test.o < "$input_file")
        run_status=$?
    fi

    # GNU timeout / gtimeout use 124 when the command is killed by timeout
    if [[ $run_status -eq 124 ]]; then
        echo -e "${C_RED}Test $base_name: TIME LIMIT (${TIME_LIMIT_SEC}s)${C_RESET}"
        continue
    fi
    if [[ $run_status -ne 0 ]]; then
        echo -e "${C_RED}Test $base_name: RUNTIME ERROR (exit $run_status)${C_RESET}"
        continue
    fi

    # Compare with expected output
    if diff -w <(echo "$actual_output") "$expected_output" > /dev/null; then
        echo -e "${C_GREEN}Test $base_name: PASSED${C_RESET}"
    else
        echo -e "${C_RED}Test $base_name: FAILED${C_RESET}"
        # echo "Expected vs Actual:"
        # diff -w "$expected_output" <(echo "$actual_output")
    fi
done < <(printf '%s\n' test_cases/*.in | sort -V)
