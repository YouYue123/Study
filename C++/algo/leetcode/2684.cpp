#include <bits/stdc++.h>
using namespace std;

// 2684. Maximum Number of Moves in a Grid [M]
// LeetCode maximum-number-of-moves-in-a-grid

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n , -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= m || i < 0 || j >= n || j < 0) return 0;
            if(j + 1 >= n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int cur = grid[i][j];
            int ans = 0;
            if(cur < grid[i][j + 1]) ans = dfs(i, j + 1) + 1;
            if(i + 1 < m && cur < grid[i + 1][j + 1]) ans = max(ans, dfs(i + 1, j + 1) + 1);
            if(i - 1 >= 0 && cur < grid[i - 1][j + 1]) ans = max(ans, dfs(i - 1, j + 1) + 1);
            return memo[i][j] = ans;
        };
        int ans = 0;
        for(int i = 0;  i < m; i ++) {
            ans = max(ans, dfs(i, 0));
        }
        return ans;
    }
};