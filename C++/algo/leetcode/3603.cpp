// 3603. Minimum Cost Path with Alternating Directions II [M]
// LeetCode minimum-cost-path-with-alternating-directions-ii

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> memo(
            m, vector<long long>(n, -1L)
        );
        auto dfs = [&](this auto&& dfs, int i, int j) -> long long{
            if(i >= m || j >= n) return LONG_LONG_MAX / 2;
            long long val = (long long)(i + 1) * (j + 1) + (long long)waitCost[i][j];
            if(i == m - 1 && j == n - 1) return val;
            if(memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = val + min(
                dfs(i + 1, j),
                dfs(i, j + 1)
            );
        };

        return dfs(0, 0) - (long long)waitCost[m - 1][n - 1] - (long long)waitCost[0][0];
    }
};