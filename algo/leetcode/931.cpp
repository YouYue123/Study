#include <bits/stdc++.h>
using namespace std;

// 931. Minimum Falling Path Sum [M]
// LeetCode minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(
            m, vector<int>(n, INT_MAX)
        );
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i >= m) return 0;
            if(j >= n || j < 0) return INT_MAX / 2;
            if(memo[i][j] != INT_MAX) return memo[i][j];
            return memo[i][j] = min({
                dfs(i + 1, j),
                dfs(i + 1, j - 1),
                dfs(i + 1, j + 1)
            }) + matrix[i][j];
        };
        int ans = INT_MAX;
        for(int i = 0; i < n; i ++) {
            ans = min(ans, dfs(0, i));
        }
        return ans;
    }
};