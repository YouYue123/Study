#include <bits/stdc++.h>
using namespace std;

// 3418. Maximum Amount of Money Robot Can Earn [M]
// LeetCode maximum-amount-of-money-robot-can-earn

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> memo(
            m,
            vector<vector<int>>(n, 
                vector<int>(3, INT_MIN)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j, int c) {
            if(i >= m || j >= n) return INT_MIN / 2;
            if(c < 0) return INT_MIN / 2;
            if(i == m - 1 && j == n - 1) {
                if(coins[i][j] >= 0) return coins[i][j];
                else return c > 0 ? 0 : coins[i][j];
            }
            if(memo[i][j][c] != INT_MIN) return memo[i][j][c];
            return memo[i][j][c] = max({
                dfs(i + 1, j, c) + coins[i][j],
                dfs(i, j + 1, c) + coins[i][j],
                dfs(i + 1, j, c - 1),
                dfs(i, j + 1, c - 1),
            });
        };

        return dfs(0, 0, 2);
    }
};