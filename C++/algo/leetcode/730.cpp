#include <bits/stdc++.h>
using namespace std;

// 730. Count Different Palindromic Subsequences [H]
// LeetCode count-different-palindromic-subsequences

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int left = i + 1, right = j - 1;
                    while (left <= right && s[left] != s[i]) left++;
                    while (left <= right && s[right] != s[i]) right--;

                    if (left > right) {
                        // 内部没有重复的 s[i] 字符，例如 "aba"
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        // 内部只有一个重复的 s[i] 字符，例如 "aaa"
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        // 内部有两个或更多重复字符，例如 "aacaa"
                        // 需要减去重复计算的中间部分 dp[left + 1][right - 1]
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    // 字符不相等时的容斥原理
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                
                // 统一处理取模，防止负数
                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
            }
        }
        return (int)dp[0][n - 1];
    }
};