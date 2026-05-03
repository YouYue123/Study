// 3573. Best Time to Buy and Sell Stock V [M]
// LeetCode best-time-to-buy-and-sell-stock-v

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector memo(
            n,
            vector(
                k,
                vector(
                    3,
                    -1LL
                )
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int txn, int state) -> long long {
            if(i == n || txn == k) {
                return state == 0 ? 0 : LLONG_MIN / 2;
            }
            if(memo[i][txn][state] != -1) return memo[i][txn][state];
            long long ans = dfs(i + 1, txn, state);
            if(state == 0) {
                ans = max({
                    ans, 
                    -prices[i] + dfs(i + 1, txn, 1), // Long
                    prices[i] + dfs(i + 1, txn, 2)   // Short
                });
            } else if(state == 1) {
                ans = max(ans, prices[i] + dfs(i + 1, txn + 1, 0));
            } else {
                ans = max(ans, -prices[i] + dfs(i + 1, txn + 1, 0));
            }
            return memo[i][txn][state] = ans;
        };
        return dfs(0, 0, 0);
    }
};