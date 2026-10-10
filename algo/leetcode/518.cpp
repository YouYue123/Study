#include <bits/stdc++.h>
using namespace std;

// 518. Coin Change II [M]
// LeetCode coin-change-ii

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector memo(
            n,
            vector(
                amount + 1,
                -1
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int amt) {
            if(amt > amount) return 0;
            if(i == n) return amt == amount ? 1 : 0;
            if(memo[i][amt] != -1) return memo[i][amt];
            return memo[i][amt] = dfs(i, amt + coins[i]) + dfs(i + 1, amt);
        };
        return dfs(0, 0);
    }
};