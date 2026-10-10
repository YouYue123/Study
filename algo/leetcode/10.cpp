#include <bits/stdc++.h>
using namespace std;

// 10. Regular Expression Matching [H]
// LeetCode regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        auto isMatch = [&](char a, char b) {
            if(a == '.' || b == '.') return true;
            return a == b;
        };
        vector memo(m + 1, vector(n + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) -> bool {
            if(i == m && j == n) return true;
            if(j == n) return false;
            if(memo[i][j] != -1) return memo[i][j] == 1;
            bool ans = false;
            if(j < n - 1 && p[j + 1] == '*') {
                char cur = p[j];
                if(dfs(i, j + 2)) {
                    ans = true;
                } else {
                    for(int k = i; k < m; k ++) {
                        if(isMatch(s[k], cur)) {
                            if(dfs(k + 1, j + 2)) {
                                ans = true;
                                break;
                            }
                        } else {
                            ans = false;
                            break;
                        }
                    }
                }
            } else {
                if(i == m) {
                    ans = false;
                } else if(isMatch(s[i], p[j])) {
                    ans = dfs(i + 1, j + 1);
                }
            }
            memo[i][j] = (ans == true ? 1 : 0);
            return ans;
        };

        return dfs(0, 0);
    }
};