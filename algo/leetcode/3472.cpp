#include <bits/stdc++.h>
using namespace std;

// 3472. Longest Palindromic Subsequence After at Most K Operations [M]
// LeetCode longest-palindromic-subsequence-after-at-most-k-operations

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        auto dist = [&] (int i, int j) {
            int d = abs(s[i] - s[j]);
            return min(d, 26 - d);
        };
        vector memo(n, vector(n, vector(k + 1, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int j, int cnt) {
            if(cnt > k) return -INF;
            if(i == j) return 1;
            if(i > j) return 0;
            if(memo[i][j][cnt] != -1) return memo[i][j][cnt];
            int ans = max(
                dfs(i + 1, j, cnt),
                dfs(i, j - 1, cnt)
            );
            ans = max(ans, 2 + dfs(i + 1, j - 1, cnt + dist(i, j)));
            return memo[i][j][cnt] = ans;
        };
        
        return dfs(0, n - 1, 0);
    }
};