// 1682. Longest Palindromic Subsequence II [M]
// LeetCode longest-palindromic-subsequence-ii

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector memo(n, vector(n, vector(27, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int j, int prev) {
            if(i >= j) return 0;
            if(memo[i][j][prev] != -1) return memo[i][j][prev] ;
            int ans = 0;
            if(s[i] == s[j] && (s[i] - 'a') != prev) {
                ans = dfs(i + 1, j - 1, s[i] - 'a') + 2;
            } else {
                ans = max(
                    dfs(i + 1, j, prev),
                    dfs(i, j - 1, prev)
                );
            }
            return memo[i][j][prev] = ans;
        };

        return max(dfs(0, n - 1, 26), 0) ;
    }
};