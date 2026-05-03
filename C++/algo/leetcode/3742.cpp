#include <bits/stdc++.h>
using namespace std;

// 3742. Maximum Path Score in a Grid [M]
// LeetCode maximum-path-score-in-a-grid

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector memo(m, vector(n, vector(k + 1, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int j, int cost) {
            if(cost > k) return -INF;
            if(memo[i][j][cost] != -1) return memo[i][j][cost];
            int score_contrib = grid[i][j];
            int cost_contrib = grid[i][j] == 0 ? 0 : 1;
            if(i == m - 1 && j == n - 1) return cost_contrib + cost <= k ? score_contrib : -INF;
            int ans = -INF;
            if(i + 1 < m) {
                ans = max(ans, score_contrib + dfs(i + 1, j,  cost + cost_contrib));
            }
            if(j + 1 < n) {
                ans = max(ans, score_contrib + dfs(i, j + 1, cost + cost_contrib));
            }
            return memo[i][j][cost] = ans;
        };

        int ans = dfs(0, 0, 0);
        return ans < 0  ? -1 : ans; 
    }
};