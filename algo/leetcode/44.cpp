#include <bits/stdc++.h>
using namespace std;

// 44. Wildcard Matching [H]
// LeetCode wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector memo(
            n + 1,
            vector(m + 1, -1)
        );
        auto dfs = [&](this auto&& dfs , int i, int j) -> bool {
            if(i >= n && j >= m) return true;
            if(j >= m) return false;
            if(i >= n) {
                while(j < m) {
                    if(p[j] != '*') return false;
                    j += 1;
                }
                return true;
            }
            if(memo[i][j] != -1) return memo[i][j];
            bool ans = false;
            if(s[i] == p[j] || p[j] == '?') {
                ans = dfs(i + 1, j + 1);
            } else if(p[j] == '*') {
                ans =  dfs(i + 1, j) || dfs(i, j + 1);
            }
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};