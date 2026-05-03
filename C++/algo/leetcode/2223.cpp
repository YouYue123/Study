// 2223. Sum of Scores of Built Strings [H]
// LeetCode sum-of-scores-of-built-strings

class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        auto get_next  = [&] (string& s) {
            int m = s.size();
            vector<int> next(m, 0);
            for(int i = 1, j = 0; i < m; i ++) {
                while(j > 0 && s[j] != s[i]) {
                    j = next[j - 1];
                }
                if(s[i] == s[j]) j += 1;
                next[i] = j;
            }
            return next;
        };
        auto next = get_next(s);
        long long ans = 0;
        vector<int> dp(n, 0);
        for(int i =1; i < n; i ++) {
            dp[i] = next[i] == 0 ? 0 : dp[next[i] - 1] + 1;
            ans += dp[i];
        }
        return ans + n;
    }
};