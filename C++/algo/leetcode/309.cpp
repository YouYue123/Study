#include <bits/stdc++.h>
using namespace std;

// 309. Best Time to Buy and Sell Stock with Cooldown [M]
// LeetCode best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector memo(
            n,
            vector(2, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int state) {
            if(i >= n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            int ans = dfs(i + 1, state);
            if(state == 0) {
                ans = max(ans, -prices[i] + dfs(i + 1, 1));
            } else {
                ans = max(ans, prices[i] + dfs(i + 2, 0));
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};