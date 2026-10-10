#include <bits/stdc++.h>
using namespace std;

// 188. Best Time to Buy and Sell Stock IV [H]
// LeetCode best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector memo(
            n, 
            vector(
                k,
                vector(
                    2,
                    -1
                )
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int cnt, int has_hold) {
            if(i == n || cnt == k) return 0;
            if(memo[i][cnt][has_hold] != -1) return memo[i][cnt][has_hold];
            int ans = 0;
            if(has_hold == 1) {
                ans = max(
                    dfs(i + 1, cnt, 1),
                    dfs(i + 1, cnt + 1, 0) + prices[i]
                );
            } else {
                ans = max(
                    dfs(i + 1, cnt, 0),
                    dfs(i + 1, cnt, 1) - prices[i]
                );
            }
            return memo[i][cnt][has_hold] = ans;
        };
        return dfs(0, 0, 0);
    }
};