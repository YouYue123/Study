#include <bits/stdc++.h>
using namespace std;

// 174. Dungeon Game [H]
// LeetCode dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> memo(
            m,
            vector<int>(n, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int j)  {
            if(i >= m || j >= n) return INT_MAX;
            if(i == m - 1 && j == n - 1) return dungeon[i][j] >= 0 ? 1 : -dungeon[i][j] + 1;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = min(
                dfs(i, j + 1),
                dfs(i + 1, j)
            ) - dungeon[i][j];
            return memo[i][j] = ans <= 0 ? 1 : ans;
        };
        return dfs(0, 0);
    }
};