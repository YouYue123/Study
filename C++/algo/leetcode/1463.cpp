#include <bits/stdc++.h>
using namespace std;

// 1463. Cherry Pickup II [H]
// LeetCode cherry-pickup-ii

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector memo(
            m, 
            vector(
                n, 
                vector(n, - 1)
            )
        );
        auto dfs = [&] (this auto&& dfs, int r, int c1, int c2) {
            if(c1 >= n || c2 >= n || c1 < 0 || c2 < 0) return INT_MIN;
            if(r >= m) return 0;
            if(memo[r][c1][c2] != -1) return memo[r][c1][c2];
            int ans = 0;
            for(int i = c1 - 1; i <= c1 + 1; i ++) {
                for(int j = c2 - 1; j <= c2 + 1; j ++) {
                    ans = max(
                        ans, 
                        dfs(r + 1, i, j)
                    );
                }
            }
            ans = ans + grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
            return memo[r][c1][c2] = ans;
        };
        
        return dfs(0, 0, n - 1);
    }
};