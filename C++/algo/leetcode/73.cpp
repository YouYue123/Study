// 73. Set Matrix Zeroes [M]
// LeetCode set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool row0_flag = false;
        bool col0_flag = false;
        
        // 1. 先记录第一行是否有 0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                row0_flag = true;
                break;
            }
        }
        
        // 2. 再记录第一列是否有 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0_flag = true;
                break;
            }
        }
        
        // 3. 使用第一行和第一列作为“备忘录”，记录其他格子是否有 0
        // 注意：这里从索引 1 开始遍历，避免污染备忘录的初始状态
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // 4. 根据第一行和第一列的备忘录，将内部的格子置 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // 5. 最后，根据之前的 flag 决定是否把第一行全部置 0
        if (row0_flag) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // 6. 根据 flag 决定是否把第一列全部置 0
        if (col0_flag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};