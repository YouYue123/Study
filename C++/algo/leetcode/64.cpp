// 64. Minimum Path Sum [M]
// LeetCode minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n , -1));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i >= m || i < 0 || j >= n || j < 0) return INT_MAX / 2;
            if(i == m - 1 && j == n - 1) return grid[i][j];
            if(memo[i][j] != -1) return memo[i][j];
            int ans =  min(
                dfs(i + 1, j),
                dfs(i, j + 1)
            ) + grid[i][j];
            return memo[i][j] = ans;
        };
        return dfs(0, 0);
    }
};