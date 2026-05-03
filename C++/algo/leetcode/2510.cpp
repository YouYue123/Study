// 2510. Check if There is a Path With Equal Number of 0's And 1's [M]
// LeetCode check-if-there-is-a-path-with-equal-number-of-0s-and-1s

class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m * n % 2 != 0) return false;
        vector memo(
            m,
            vector(
                n, 
                vector(m + n + 1, -1)
            )
        );
        if(m * n % 2 == 1) return false;
        auto dfs = [&](this auto&& dfs, int i, int j, int cur) {
            if(i >= m || j >= n) return false;
            if(cur > (m + n) / 2 || cur < -(m + n) / 2) return false;
            int k = cur + (m + n) / 2;
            if(memo[i][j][k] != -1) return memo[i][j][k] == 1 ? true : false;
            int nx = cur + (grid[i][j] == 0 ? -1 : 1);
            if(i == m - 1 && j == n - 1) return nx == 0;
            bool ans = dfs(i + 1, j, nx) || dfs(i, j + 1, nx);
            memo[i][j][k] = ans ? 1 : 0;
            return ans;
        };
        return dfs(0, 0, 0);
    }
};