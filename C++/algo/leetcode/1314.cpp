// 1314. Matrix Block Sum [M]
// LeetCode matrix-block-sum

class Solution {
public:        
    vector<vector<int>> preSum;

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        preSum.assign(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i ++)  {
            for(int j = 1; j <= n; j ++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + mat[i - 1][j - 1] - preSum[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans;
        ans.assign(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                 // 左上角的坐标
                int x1 = max(i - k, 0);
                int y1 = max(j - k, 0);
                // 右下角坐标
                int x2 = min(i + k, m - 1);
                int y2 = min(j + k, n - 1);
                ans[i][j] = sumRegion(x1, y1, x2, y2);
            }
        }
        return ans;
    }
    int sumRegion(int x1, int y1, int x2, int y2) {
        return preSum[x2 + 1][y2 + 1] - preSum[x1][y2 + 1] - preSum[x2 + 1][y1] + preSum[x1][y1];
    }
};