// 1886. Determine Whether Matrix Can Be Obtained By Rotation [E]
// LeetCode determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        auto isEqual = [&] () {
            for(int i = 0; i < n; i ++) {
                for(int j = 0; j < n; j ++) {
                    if(mat[i][j] != target[i][j]) return false;
                }
            }
            return true;
        };
        auto rotate = [&] () {
            auto tmp = mat;
            for(int i = 0; i < n; i ++) {
                for(int j = 0; j < n; j ++) {
                    tmp[j][n - 1 - i] = mat[i][j];
                }
            }
            return tmp;
        };
        if(isEqual()) return true;
        for(int i = 0; i < 3; i ++) {
            mat = rotate();
            if(isEqual()) return true;
        }
        return false;
    }
};