#include <bits/stdc++.h>
using namespace std;

// 2944. Minimum Number of Coins for Fruits [M]
// LeetCode minimum-number-of-coins-for-fruits

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i >= n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = prices[i] + dfs(2 * i + 2);
            for(int j = i + 1; j < n && j <= 2 * i + 1; j ++) {
                ans = min(ans, dfs(j) + prices[i]);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};