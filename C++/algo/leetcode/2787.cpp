#include <bits/stdc++.h>
using namespace std;

// 2787. Ways to Express an Integer as Sum of Powers [M]
// LeetCode ways-to-express-an-integer-as-sum-of-powers

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector memo(
            302,
            vector(
                n + 1,
                -1
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int target) {
            if(target == 0) return 1;
            if(target < 0) return 0;
            if(memo[i][target] != -1) return memo[i][target];
            int cur = pow(i, x);
            if(cur > target) return 0;
            return memo[i][target] = (dfs(i + 1, target - cur) + dfs(i + 1, target)) % MOD;
        };
        return dfs(1, n);
    }
};