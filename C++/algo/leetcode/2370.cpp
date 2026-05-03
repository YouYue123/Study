// 2370. Longest Ideal Subsequence [M]
// LeetCode longest-ideal-subsequence

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int ans = 0;
        int dp[26] = {};
        for(int i = 0; i < n; i ++) {
            int c = s[i] - 'a';
            int nxtVal = 0;
            for(int j = max(0, c - k); j <= min(25, c + k); j ++) {
                nxtVal = max(nxtVal, dp[j] + 1);
            }
            dp[c] = nxtVal;
            ans = max(ans, dp[c]);
        }
        return ans;
    }
};