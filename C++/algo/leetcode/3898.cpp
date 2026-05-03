// 3898. Find the Degree of Each Vertex [E]
// LeetCode find-the-degree-of-each-vertex

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector ans(n, 0);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == 1) ans[i] += 1;
            }
        }
        return ans;
    }
};