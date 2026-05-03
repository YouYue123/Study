// 712. Minimum ASCII Delete Sum for Two Strings [M]
// LeetCode minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector memo(n + 1, vector(m + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i == n && j == m) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(i == n) {
                ans = dfs(i, j + 1) + s2[j];
            } else if(j == m) {
                ans =  dfs(i + 1, j) + s1[i];
            } else if(s1[i] == s2[j]) {
                ans = dfs(i + 1, j + 1);
            } else {
                ans = min(
                    dfs(i + 1, j) + s1[i],
                    dfs(i, j + 1) + s2[j]
                );
            }
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};