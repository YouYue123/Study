#include <bits/stdc++.h>
using namespace std;

// 2950. Number of Divisible Substrings [M]
// LeetCode number-of-divisible-substrings

class Solution {
public:
    int countDivisibleSubstrings(string word) {
        unordered_map<char, int> charMap = {
            {'a', 1}, {'b', 1}, 
            {'c', 2}, {'d', 2}, { 'e', 2},
            {'f', 3}, {'g', 3}, { 'h', 3},
            {'i', 4}, {'j', 4}, { 'k', 4},
            {'l', 5}, {'m', 5}, { 'n', 5},
            {'o', 6}, {'p', 6}, { 'q', 6},
            {'r', 7}, {'s', 7}, { 't', 7},
            {'u', 8}, {'v', 8}, { 'w', 8},
            {'x', 9}, {'y', 9}, { 'z', 9},
        };
        int ans = 0;
        vector<int> presum(word.size() + 1, 0);
        for(int i = 1; i <= word.size(); i ++) {
            presum[i] = presum[i - 1] + charMap[word[i - 1]];
        }
        for(int i = 0; i < word.size(); i ++) {
            for(int j = 0; j <= i; j ++) {
                int len = i - j + 1;
                // cout << word.substr(j, len) << endl;; 
                // [j, i]
                int sum = presum[i + 1] - presum[j];
                // cout << sum << " " << len << endl;
                if(sum % len == 0) ans += 1;
            }
         }
         return ans;
    }
};