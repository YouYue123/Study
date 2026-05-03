// 115. Distinct Subsequences [H]
// LeetCode distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector memo(
            n,
            vector(m, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(j == m) return 1;
            if(i >= n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = 0;
            if(s[i] == t[j]) ans += dfs(i + 1, j + 1);
            ans += dfs(i + 1, j);
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};