#include <bits/stdc++.h>
using namespace std;

// 516. Longest Palindromic Subsequence [M]
// LeetCode longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == j) return 1;
            if(i > j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(s[i] == s[j]) {
                ans = dfs(i + 1, j - 1) + 2;
            } else {
                ans = max(
                    dfs(i + 1, j),
                    dfs(i, j - 1)
                );
            }
            return memo[i][j] = ans;
        };

        vector dp(n + 1, vector(n + 1, 0));
        for(int i = n - 1; i >= 0; i --) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j ++) {
                int ans = 0;
                if(s[i] == s[j]) {
                    ans = dp[i + 1][j - 1] + 2;
                } else {
                    ans = max(
                        dp[i + 1][j],
                        dp[i][j - 1]
                    );
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};