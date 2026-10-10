#include <bits/stdc++.h>
using namespace std;

// 741. Cherry Pickup [H]
// LeetCode cherry-pickup

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector memo(n * 2 - 1, vector(n, vector<int>(n, -1))); // -1 表示没有计算过
        auto dfs = [&](this auto&& dfs, int t, int j, int k) -> int {
            if (j < 0 || k < 0 || t < j || t < k || grid[t - j][j] < 0 || grid[t - k][k] < 0) return INT_MIN;
            if (t == 0) return grid[0][0];
            if (memo[t][j][k] != -1) return memo[t][j][k];
            return memo[t][j][k] = max({
                    // 枚举前一位置可能
                    dfs(t - 1, j, k),      // 两人都\U0001f447
                    dfs(t - 1, j, k - 1),  // a\U0001f447，b\U0001f449
                    dfs(t - 1, j - 1, k),  // a\U0001f449，b\U0001f447
                    dfs(t - 1, j - 1, k - 1) // a\U0001f449，b\U0001f449
                }) + grid[t - j][j] + (k != j ? grid[t - k][k] : 0);
        };
        return max(dfs(n * 2 - 2, n - 1, n - 1), 0);
    }
};