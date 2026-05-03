// 97. Interleaving String [M]
// LeetCode interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;
        vector memo(
            n + 1,
            vector(
                m + 1,
                -1
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if(i >= n && j >= m) return true;
            if(memo[i][j] != -1) return memo[i][j];
            bool ans = false;
            if(i < n && s1[i] == s3[i + j]) ans = ans || dfs(i + 1, j);
            if(j < m && s2[j] == s3[i + j]) ans = ans || dfs(i, j + 1);
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};