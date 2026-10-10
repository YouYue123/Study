#include <bits/stdc++.h>
using namespace std;

// 3725. Count Ways to Choose Coprime Integers from Rows [H]
// LeetCode count-ways-to-choose-coprime-integers-from-rows

int MOD = 1e9 + 7;
class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector memo(m, vector(150 * 150 + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int g) {
            if(i == m) return g == 1 ? 1 : 0;
            if(memo[i][g] != -1) return memo[i][g];
            int ans = 0;
            for(int j = 0; j < n; j ++) {
                ans = (ans + dfs(i + 1, gcd(g, mat[i][j]))) % MOD;
            }
            return memo[i][g] = ans;
        };
        return dfs(0, 0);
    }
};