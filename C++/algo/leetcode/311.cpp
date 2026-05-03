// 311. Sparse Matrix Multiplication [M]
// LeetCode sparse-matrix-multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        vector<vector<int>> ans(
            m,
            vector<int>(n, 0)
        );
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j ++) {
                for(int p = 0 ; p < k; p ++) {
                    ans[i][j] += mat1[i][p] * mat2[p][j];
                }
            }
        }
        return ans;
    }
};