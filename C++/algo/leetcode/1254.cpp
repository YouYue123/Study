#include <bits/stdc++.h>
using namespace std;

// 1254. Number of Closed Islands [M]
// LeetCode number-of-closed-islands

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, -1}, {0, 1}
        };
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&] (this auto&& dfs, int i, int j) -> void {
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if(grid[ni][nj] != 0) continue;
                grid[ni][nj] = 2;
                dfs(ni, nj);
            }
        };
        for(int i = 0; i < m ; i ++) {
            dfs(i, -1);
            dfs(i, n);
        }
        for(int i = 0; i < n; i ++) {
            dfs(-1, i);
            dfs(m, i);
        }
        int ans = 0;
        auto dfs2 = [&] (this auto&& dfs2, int i, int j) -> void {
            for(auto& d : dirs) {
                int ni = i + d.first, nj = j + d.second;
                if(ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                if(grid[ni][nj] != 0) continue;
                grid[ni][nj] = 2;
                dfs(ni, nj);
            }
        };
        for(int i = 0 ; i < m ; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 0) {
                    ans += 1;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};