#include <bits/stdc++.h>
using namespace std;

// 463. Island Perimeter [E]
// LeetCode island-perimeter

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(grid[i][j] == 1) {
                    for(auto& p : dirs) {
                        int ni = i + p.first, nj = j + p.second;
                        if(ni >= m || ni < 0 || nj >= n || nj < 0) {
                            ans += 1;
                        } else if(grid[ni][nj] == 0) {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};