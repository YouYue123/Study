// 2435. Paths in Matrix Whose Sum Is Divisible by K [H]
// LeetCode paths-in-matrix-whose-sum-is-divisible-by-k

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector memo(
            m,
            vector(
                n,
                vector(k, -1LL)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int j, long long curSum) {
            if(i >= m | j >=n || i < 0 || j < 0) return 0LL;
            if(i == m - 1 && j == n - 1) return (curSum + grid[i][j]) % k == 0 ? 1LL : 0LL;
            if(memo[i][j][curSum] != -1) return memo[i][j][curSum];
            long long nxSum = (curSum + grid[i][j]) % k;
            return memo[i][j][curSum] = (dfs(i + 1, j, nxSum) + dfs(i, j + 1, nxSum)) % MOD;
        };
        return dfs(0, 0, 0LL);
    }
};