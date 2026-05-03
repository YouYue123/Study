#include <bits/stdc++.h>
using namespace std;

// 2088. Count Fertile Pyramids in a Land [H]
// LeetCode count-fertile-pyramids-in-a-land

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector dp(m, vector(n, 0));
        int ans = 0;
        auto solve = [&] () {
            for(int i = 0; i < m; i++) fill(dp[i].begin(), dp[i].end(), 0);
            for(int j = 0; j < n; j++) dp[m - 1][j] = grid[m - 1][j];
            for(int i = m - 2; i >= 0; i --) {
                for(int j = 0; j < n; j ++) {
                    if(grid[i][j] == 1) {
                        if(j > 0 && j + 1 < n) {
                            dp[i][j] = min({
                                dp[i + 1][j - 1],
                                dp[i + 1][j],
                                dp[i + 1][j + 1]
                            }) + 1;
                        } else {
                            dp[i][j] = 1;
                        }
                        ans += dp[i][j] - 1;
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        };
        solve();
        reverse(grid.begin(), grid.end());
        solve();
        return ans;
    }
};