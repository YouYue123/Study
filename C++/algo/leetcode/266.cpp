#include <bits/stdc++.h>
using namespace std;

// 266. Palindrome Permutation [E]
// LeetCode palindrome-permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> dict;
        for(char c : s) {
            dict[c] += 1;
        }
        int oddCount = 0;
        for (auto c : dict) {
            oddCount += c.second % 2 == 0 ? 0 : 1;
        }
        // cout << oddCount;
        return oddCount <= 1;
    }
};