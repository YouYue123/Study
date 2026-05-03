#include <bits/stdc++.h>
using namespace std;

// 1155. Number of Dice Rolls With Target Sum [M]
// LeetCode number-of-dice-rolls-with-target-sum

int MOD = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector memo(
            n,
            vector(
                target + 1,
                -1LL
            )
        );
        auto dfs =[&](this auto&& dfs, int i, int target) {
            // cout << i << " " << target << endl;
            if(target < 0) return 0LL;
            if(i >= n) return target == 0 ? 1LL : 0LL;
            if(memo[i][target] != -1) return memo[i][target];
            long long ans = 0;
            for(int d = 1; d <= k; d ++) {
                ans = (ans + dfs(i + 1, target - d)) % MOD;
            }
            return memo[i][target] = ans;
        };
        return dfs(0, target);
    }
};