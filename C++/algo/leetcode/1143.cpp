// 1143. Longest Common Subsequence [M]
// LeetCode longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // vector memo(m, vector(n, -1));
        // auto dfs = [&] (this auto&& dfs, int i, int j) {
        //     if(i == m || j == n) return 0;
        //     if(memo[i][j] != -1) return memo[i][j];
        //     int ans = 0;
        //     if(text1[i] == text2[j]) {
        //         ans = dfs(i + 1, j + 1) + 1;
        //     } else {
        //         ans = max(
        //             dfs(i + 1, j),
        //             dfs(i, j + 1)
        //         );
        //     }
        //     return memo[i][j] = ans;
        // };
        vector dp(m + 1, vector(n + 1, 0));
        for(int i = 0; i <= n; i ++) dp[m][i] = 0;
        for(int i = 0; i <= m; i ++) dp[i][n] = 0;
        for(int i = m - 1; i >= 0; i --) {
            // if(i == m - 1) dp[i][]
            for(int j = n - 1; j >= 0; j --) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = max(
                        dp[i + 1][j],
                        dp[i][j + 1]
                    );
                }
            }
        }
        return dp[0][0];
    }
};