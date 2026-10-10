#include <bits/stdc++.h>
using namespace std;

// 2291. Maximum Profit From Trading Stocks [M]
// LeetCode maximum-profit-from-trading-stocks

class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        vector memo(
            n,
            vector(
                budget + 1,
                -1
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int b) {
            if(b < 0) return INT_MIN / 2;
            if(i == n) return 0;
            if(memo[i][b] != -1) return memo[i][b];
            return memo[i][b] = max(
                dfs(i + 1, b),
                dfs(i + 1, b - present[i]) + (future[i] - present[i])
            );
        };
        return dfs(0, budget);
    }
};