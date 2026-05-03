// 1020. Number of Enclaves [M]
// LeetCode number-of-enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {-1, 0}, {1, 0}
        };
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i < 0 || i >= m || j < 0 || j >= n) return;
            if(grid[i][j] == 0) return;
            // cout << i << " " << j << endl;
            grid[i][j] = 0;
            for(auto& p : dirs) dfs(i + p.first, j + p.second);
        };
        for(int i = 0; i < m; i ++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for(int j = 0; j < n; j ++) {
            dfs(0, j);
            dfs(m - 1, j);
        }
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                // cout << grid[i][j] << " ";
                if(grid[i][j] == 1) ans += 1;
            }
            // cout << endl;
        }
        return ans;
    }
};