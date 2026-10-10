#include <bits/stdc++.h>
using namespace std;

// 3122. Minimum Number of Operations to Satisfy Conditions [M]
// LeetCode minimum-number-of-operations-to-satisfy-conditions

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector cnt(n, vector(10, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int num = grid[i][j];
                cnt[j][num] += 1;
            }
        }
        vector memo(n, vector(11, -1));
        auto dfs = [&] (this auto&& dfs, int col, int prevNum) {
            if(col == n) return 0;
            if(memo[col][prevNum] != -1) return memo[col][prevNum];
            int ans = -INF;
            for(int k = 0; k <= 9; k ++) {
                if(k == prevNum) continue;
                ans = max(
                    ans,
                    dfs(col + 1, k) + cnt[col][k]
                );
            }
            return memo[col][prevNum] = ans;
        };

        return m * n - dfs(0, 10);
    }
};