#include <bits/stdc++.h>
using namespace std;

// 459. Repeated Substring Pattern [E]
// LeetCode repeated-substring-pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
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
        return next.back() != 0 && n % (n - next.back()) == 0;
    }
};