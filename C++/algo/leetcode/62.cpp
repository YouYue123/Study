// 62. Unique Paths [M]
// LeetCode unique-paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector memo(m, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == m - 1 && j == n - 1) return 1;
            if(i >= m || j >= n) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        };

        return dfs(0, 0);
    }
};