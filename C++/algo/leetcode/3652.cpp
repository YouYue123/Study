#include <bits/stdc++.h>
using namespace std;

// 3652. Best Time to Buy and Sell Stock using Strategy [M]
// LeetCode best-time-to-buy-and-sell-stock-using-strategy

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> preSum(n + 1);
        for(int i = 0; i < n; i ++) preSum[i + 1] = preSum[i] + prices[i];
        vector<array<long long, 2>> memo(n, { LLONG_MIN, LLONG_MIN});
        auto dfs = [&] (this auto&& dfs, int i, bool used) {
            if(i == n) return 0LL;
            if(memo[i][used] != LLONG_MIN) return memo[i][used];
            long long ans = dfs(i + 1, used) + prices[i] * strategy[i];
            if(!used && i + k <= n) {
                ans = max(
                    ans,
                    dfs(i + k, true) + (preSum[i + k] - preSum[i + k / 2])
                );
            }
            return  memo[i][used] = ans;
        };
        return dfs(0, false);
    }
};