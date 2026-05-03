#include <bits/stdc++.h>
using namespace std;

// 3130. Find All Possible Stable Binary Arrays II [H]
// LeetCode find-all-possible-stable-binary-arrays-ii

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        vector memo(
            zero + 1,
            vector(
                one + 1,
                vector(
                    2,
                    -1LL
                )
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int j, int k) -> int {
            if(i == 0) return j <= limit && k == 1;
            if(j == 0) return i <= limit && k == 0;
            if(memo[i][j][k] != -1) return memo[i][j][k];
            long long ans = 0;
            if(k == 0) {
                ans = (dfs(i - 1, j, 0) + dfs(i - 1, j, 1)) % MOD;
                if(i > limit) {
                    ans = (ans + MOD - dfs(i - limit - 1, j, 1)) % MOD;
                }
            } else {
                ans = (dfs(i, j - 1, 0) + dfs(i , j - 1, 1)) % MOD;
                if(j > limit) {
                    ans = (ans + MOD - dfs(i, j - limit - 1, 0)) % MOD;
                }
            }
            return memo[i][j][k] = ans;
        };
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};