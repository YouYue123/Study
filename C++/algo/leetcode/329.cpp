// 329. Longest Increasing Path in a Matrix [H]
// LeetCode longest-increasing-path-in-a-matrix

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(
            m,
            vector<int>(n, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            int cur = matrix[i][j];
            int ans = 1;
            if(memo[i][j] != -1) return memo[i][j];
            if(i + 1 < m && cur < matrix[i + 1][j])  ans = max(ans, dfs(i + 1, j) + 1);
            if(i - 1 >= 0 && cur < matrix[i - 1][j]) ans = max(ans, dfs(i - 1, j) + 1);
            if(j + 1 < n && cur < matrix[i][j + 1]) ans = max(ans, dfs(i, j + 1) + 1);
            if(j - 1 >= 0 && cur < matrix[i][j - 1]) ans = max(ans, dfs(i, j - 1) + 1);
            return memo[i][j] = ans;
        };
        int ans = INT_MIN;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};