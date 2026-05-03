// 2304. Minimum Path Cost in a Grid [M]
// LeetCode minimum-path-cost-in-a-grid

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        auto dfs = [&](this auto&&dfs, int i, int j) {
            if(i == m - 1) return grid[i][j];
            if(memo[i][j] != -1) return memo[i][j];
            int val = grid[i][j];
            int minCost = INT_MAX;
            for(int nj = 0; nj < n; nj += 1) {
                minCost = min(minCost, dfs(i + 1, nj) + moveCost[val][nj]);
            }
            return memo[i][j] = minCost + val;
        };
        int ans = INT_MAX;
        for(int i = 0; i < n; i ++) {
            ans = min(ans, dfs(0, i));
        }
        // for(int i = 0; i < m; i ++) {
        //     for(int j = 0; j < n; j ++) {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};