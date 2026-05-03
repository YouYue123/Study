// 1975. Maximum Matrix Sum [M]
// LeetCode maximum-matrix-sum

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int negCnt = 0;
        int absMin = INF;
        long long posSum = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j++) {
                int num = matrix[i][j];
                posSum += abs(num);
                if(num < 0) negCnt += 1;
                absMin = min(absMin, abs(num));
            }
        }
        if(negCnt % 2 == 0) return posSum;
        return posSum - 2 * absMin;
    }
};