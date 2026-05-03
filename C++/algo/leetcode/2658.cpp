// 2658. Maximum Number of Fish in a Grid [M]
// LeetCode maximum-number-of-fish-in-a-grid

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= m || i < 0 || j >= n || j < 0) return 0;
            if(grid[i][j] == 0 || visited[i][j]) return 0;
            visited[i][j] = true;
            int ans = grid[i][j];
            for(auto &p : dirs) {
                int ni = i + p.first, nj = j + p.second;
                ans += dfs(ni, nj);
            }
            return ans;
        };
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};