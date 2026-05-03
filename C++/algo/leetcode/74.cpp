// 74. Search a 2D Matrix [M]
// LeetCode search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int targetRow = left - 1;
        if(targetRow < 0) return false;
        left = 0, right = matrix[targetRow].size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(matrix[targetRow][mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left < matrix[0].size() && matrix[targetRow][left] == target;
    }
};