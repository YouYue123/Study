#include <bits/stdc++.h>
using namespace std;

// 695. Max Area of Island [M]
// LeetCode max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= m || i < 0 || j >= n || j < 0) return 0;
            if(visited[i][j] || grid[i][j] == 0) return 0;
            visited[i][j] = true;
            int ans = 1;
            for(auto& p : dirs) {
                ans += dfs(i + p.first, j + p.second);
            }
            return ans;
        };
        int ans = 0;
        for(int i = 0 ;i  < m ; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};