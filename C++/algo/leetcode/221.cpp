// 221. Maximal Square [M]
// LeetCode maximal-square

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0, topLeft = 0;
        vector dp(n, 0);
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                int nxtTopLeft = dp[j];
                if(matrix[i][j] == '0') {
                    dp[j] = 0;
                    continue;
                };
                dp[j] = 1 + min({
                    dp[j],
                    j - 1 >=0 ? dp[j - 1] : 0,
                    topLeft,
                });
                topLeft = nxtTopLeft;
                ans = max(ans, dp[j]);
            }
            topLeft = 0;
        }
        return ans * ans;
    }
};