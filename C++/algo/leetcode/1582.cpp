// 1582. Special Positions in a Binary Matrix [E]
// LeetCode special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<int> row_sum(m, 0);
        vector<int> col_sum(n, 0);
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                row_sum[i] += mat[i][j];
                col_sum[j] += mat[i][j];
            }
        }
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(mat[i][j] == 1 && row_sum[i] == 1 && col_sum[j] == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};