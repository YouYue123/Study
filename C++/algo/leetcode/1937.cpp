// 1937. Maximum Number of Points with Cost [M]
// LeetCode maximum-number-of-points-with-cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        vector<long long> left(n, 0), right(n, 0);
        for (int j = 0; j < n; j++)  dp[0][j] = points[0][j];
        for (int i = 1; i < m; i++) {
            left[0] = dp[i-1][0], right[n-1] = dp[i-1][n-1] - (n-1);
            for (int j = 1; j < n; j++)    left[j] = max(left[j-1], dp[i-1][j] + j);
            for (int j = n-2; j >= 0; j--) right[j] = max(right[j+1], dp[i-1][j] - j);
            for (int j = 0; j < n; j++)    dp[i][j] = points[i][j] + max(left[j] - j, right[j] + j);
        }
        long long ans = 0;
        for (int j = 0; j < n; j++) ans = max(ans, dp[m-1][j]);
        return ans;
    }
};