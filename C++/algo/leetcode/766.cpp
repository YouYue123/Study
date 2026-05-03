// 766. Toeplitz Matrix [E]
// LeetCode toeplitz-matrix

class Solution {
public:
       bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp.count(i - j) == 0)
                    mp[i - j] = matrix[i][j];
                else if (mp[i - j] != matrix[i][j])
                    return 0;
            }
        }
        return 1;
    } 
    
};