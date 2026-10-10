#include <bits/stdc++.h>
using namespace std;

// 322. Coin Change [M]
// LeetCode coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector memo(n, 
            vector(amount + 1, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, long long amt) {
            if(amt > amount) return INT_MAX / 2;
            if(i == n) return amt == amount ? 0 : INT_MAX;
            if(memo[i][amt] != -1) return memo[i][amt];
            return memo[i][amt] = min(
                dfs(i, amt + coins[i]) + 1,
                dfs(i + 1, amt)
            );
        };
        int ans = dfs(0, 0);
        return ans > INT_MAX / 2 ? -1 : ans;
    }
};