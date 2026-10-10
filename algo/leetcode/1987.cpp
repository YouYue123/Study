#include <bits/stdc++.h>
using namespace std;

// 1987. Number of Unique Good Subsequences [H]
// LeetCode number-of-unique-good-subsequences

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int dict[2] = {};
        bool hasZero = 0;
        for(char c : binary) {
            if(c == '0') {
                dict[0] = (dict[0] + dict[1]) % MOD;
                hasZero = true;
            } else {
                dict[1] = (dict[0] + dict[1] + 1) % MOD;
            }
        }
        return (dict[0] + dict[1] + (hasZero ? 1 : 0)) % MOD;
    }
};