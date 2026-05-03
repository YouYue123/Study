// 123. Best Time to Buy and Sell Stock III [H]
// LeetCode best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector memo(
            n,
            vector(
                2,
                vector(
                    2,
                    -1
                )
            )
        );
        auto dfs = [&] (this auto&&dfs, int i, int txn_cnt, int has_hold) {
            if(i == n || txn_cnt == 2) return 0;
            if(memo[i][txn_cnt][has_hold] != -1) return memo[i][txn_cnt][has_hold]; 
            int ans = 0;
            if(has_hold == 1) {
                ans = max(
                    dfs(i + 1, txn_cnt, has_hold),
                    dfs(i + 1, txn_cnt + 1, 0) + prices[i]
                );
            } else {
                ans = max(
                    dfs(i + 1, txn_cnt, 0),
                    dfs(i + 1, txn_cnt, 1) - prices[i]
                );
            }
            return memo[i][txn_cnt][has_hold] = ans;
        };

        return dfs(0, 0, false);
    }
};