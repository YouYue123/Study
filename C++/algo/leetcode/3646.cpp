#include <bits/stdc++.h>
using namespace std;

// 3646. Next Special Palindrome Number [H]
// LeetCode next-special-palindrome-number

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long specialPalindrome(long long n) {
        std::string s_n = std::to_string(n);
        int l_n = s_n.length();
        long long ans = -1; // Using -1 as a sentinel for infinity

        // Pre-categorize valid digit set masks by the length they produce.
        std::vector<std::vector<int>> masks_by_len(46);
        for (int i = 1; i < (1 << 9); i++) {
            int odd_count = 0;
            int total_len = 0;
            for (int j = 0; j < 9; j++) {
                if ((i >> j) & 1) { // If digit (j+1) is in the set
                    int digit = j + 1;
                    total_len += digit;
                    if (digit % 2 != 0) {
                        odd_count++;
                    }
                }
            }
            
            if (odd_count <= 1 && total_len < masks_by_len.size()) {
                masks_by_len[total_len].push_back(i);
            }
        }

        // Helper lambda to form a palindrome from a mask and a half-string
        auto form_palindrome = [](int mask, const std::string& half_str) -> long long {
            int center = -1;
            for (int j = 0; j < 9; j++) {
                if (((mask >> j) & 1) && ((j + 1) % 2 != 0)) {
                    center = j + 1;
                    break;
                }
            }
            std::string full_str = half_str;
            if (center != -1) {
                full_str += std::to_string(center);
            }
            std::string reversed_half = half_str;
            std::reverse(reversed_half.begin(), reversed_half.end());
            full_str += reversed_half;

            if (full_str.empty()) return -1;
            if (full_str.length() > 19 || (full_str.length() == 19 && full_str > "9223372036854775807")) {
                return -1; // Handle overflow
            }
            return std::stoll(full_str);
        };

        // This loop now correctly combines both cases (same length and longer length)
        // without a faulty early exit.
        for (int l = l_n; l <= 19 && l < masks_by_len.size(); l++) {
            for (int mask : masks_by_len[l]) {
                std::string half_digits_str;
                for (int j = 0; j < 9; j++) {
                    if ((mask >> j) & 1) {
                        int digit = j + 1;
                        half_digits_str += std::string(digit / 2, '0' + digit);
                    }
                }
                std::sort(half_digits_str.begin(), half_digits_str.end());

                if (l > l_n) {
                    // Case 2: Longer length - only need the smallest palindrome
                    long long p = form_palindrome(mask, half_digits_str);
                    if (p != -1) {
                        if (ans == -1 || p < ans) ans = p;
                    }
                } else { // l == l_n
                    // Case 1: Same length - must check permutations
                    do {
                        long long p = form_palindrome(mask, half_digits_str);
                        if (p != -1 && p > n) {
                            if (ans == -1 || p < ans) ans = p;
                            break; // Optimization: Found smallest from this set
                        }
                    } while (std::next_permutation(half_digits_str.begin(), half_digits_str.end()));
                }
            }
        }
        return ans;
    }
};