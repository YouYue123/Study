// 2328. Number of Increasing Paths in a Grid [H]
// LeetCode number-of-increasing-paths-in-a-grid

int MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        vector<vector<int>> memo(m,
            vector<int>(n, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i >= m || j >= n || i < 0 || j < 0) return 0;
            int cur = grid[i][j];
            int ans = 1;
            if(memo[i][j] != -1) return memo[i][j];
            for(auto& d: dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < m && ni >= 0 && nj < n && nj >= 0) {
                    if(grid[ni][nj] > cur) ans = ((long long)ans + dfs(ni, nj)) % MOD;
                }
            }
            return memo[i][j] = ans;
        };
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                ans =((long long) ans +  dfs(i, j)) % MOD;
            }
        }
        return ans;
    }
};