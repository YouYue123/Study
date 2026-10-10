#include <bits/stdc++.h>
using namespace std;

// 1392. Longest Happy Prefix [H]
// LeetCode longest-happy-prefix

class Solution {
public:
    string longestPrefix(string s) {
        auto get_next = [&] (string& s) {
            int m = s.size();
            vector<int> next(m, 0);
            for(int i = 1, j = 0; i < m; i ++) {
                while(j > 0 && s[i] != s[j]) {
                    j = next[j - 1];
                }
                if(s[i] == s[j]) j += 1;
                next[i] = j;
            }
            return next;
        };
        auto next = get_next(s);
        int maxLen = next.back();
        int n = s.size();
        return s.substr(n - maxLen);
    }
};