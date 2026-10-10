#include <bits/stdc++.h>
using namespace std;

// 3665. Twisted Mirror Path Count [M]
// LeetCode twisted-mirror-path-count

int MOD = 1e9 + 7;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Right -> 0, down -> 1
        vector<vector<vector<long long>>> memo(
            m,
            vector<vector<long long>>(
                n,
                vector<long long>(2, -1)
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int j, int enter) -> long long {
            if(i >= m || j >= n) return 0;
            if(i == m - 1 && j == n - 1) return 1;
            if(memo[i][j][enter] != -1) return memo[i][j][enter];
            if(grid[i][j] == 0) {
                return memo[i][j][enter] = (dfs(i + 1, j, 1) + dfs(i, j + 1, 0)) % MOD;
            } else {
                if(enter == 0) {
                    return memo[i][j][enter] = dfs(i + 1, j, 1);
                } else {
                    return memo[i][j][enter] = dfs(i, j + 1, 0);
                }
            }
        };
        return dfs(0, 0, 0);
    }
};