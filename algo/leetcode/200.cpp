#include <bits/stdc++.h>
using namespace std;

// 200. Number of Islands [M]
// LeetCode number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector visited(m, vector(n, false));
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(visited[i][j] == true) return;
            visited[i][j] = true;
            for(auto& dir : dirs) {
                int nxt_i = i + dir.first, nxt_j = j + dir.second;
                if(nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n) continue;
                if(grid[nxt_i][nxt_j] == '0') continue;
                // cout << nxt_i << " " << nxt_j << endl;
                dfs(nxt_i, nxt_j);
            }
        };
        int ans = 0;
        for(int i = 0; i < m;  i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    ans += 1;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};