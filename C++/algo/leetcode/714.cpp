// 714. Best Time to Buy and Sell Stock with Transaction Fee [M]
// LeetCode best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector memo(
            n,
            vector(
                2,
                -1
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int has_hold) {
            if(i == n) return 0;
            if(memo[i][has_hold] != -1) return memo[i][has_hold];
            int ans = 0;
            if(has_hold == 1) {
                ans = max(
                    dfs(i + 1, 1),
                    dfs(i + 1, 0) + prices[i] - fee
                );
            } else {
                ans = max(
                    dfs(i + 1, 0),
                    dfs(i + 1, 1) - prices[i]
                );
            }
            return memo[i][has_hold] = ans;
        };
        return dfs(0, 0);
    }
};