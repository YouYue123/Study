// 1277. Count Square Submatrices with All Ones [M]
// LeetCode count-square-submatrices-with-all-ones

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector memo(m, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= m || j >= n) return 0;
            if(matrix[i][j] == 0) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            return memo[i][j] = min({
                dfs(i + 1, j),
                dfs(i, j + 1),
                dfs(i + 1, j + 1)
            }) + 1;
        };
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                ans += dfs(i, j);
            }
        }
        return ans;
    }
};