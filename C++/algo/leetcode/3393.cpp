#include <bits/stdc++.h>
using namespace std;

// 3393. Count Paths With the Given XOR Value [M]
// LeetCode count-paths-with-the-given-xor-value

int MOD = 1e9 + 7;
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(
                n, vector<int>(16, -1)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j, int val) {
            if(i >= m || j >= n) return 0;
            int nxVal = val ^ grid[i][j];
            if(i == m -1 && j == n - 1) return nxVal == k ? 1 : 0;
            if(memo[i][j][val] != -1) return memo[i][j][val];
            return memo[i][j][val] = ((long long)dfs(i + 1, j, nxVal) + (long long)dfs(i, j + 1, nxVal)) % MOD;
        };
        return dfs(0, 0, 0);
    }
};