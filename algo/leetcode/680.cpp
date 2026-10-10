#include <bits/stdc++.h>
using namespace std;

// 680. Valid Palindrome II [E]
// LeetCode valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        auto is_p = [&] (int i, int j) {
            if(i >= j) return true;
            while(i < j) {
                if(s[i] != s[j]) return false;
                i += 1;
                j -= 1;
            }
            return true;
        };
        int left = 0, right = n - 1;
        while(left < right) {
            if(s[left] != s[right]) {
                return is_p(left + 1, right) || is_p(left, right - 1);
            } 
            left += 1;
            right -= 1;
        }
        return true;
    }
};