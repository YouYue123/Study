// 63. Unique Paths II [M]
// LeetCode unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> memo(
            m,
            vector<int> (n, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == m - 1 && j == n - 1) return 1;
            if(i >= m || j >= n) return 0;
            if(obstacleGrid[i][j] == 1) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        };
        return dfs(0, 0);
    }
};