// 54. Spiral Matrix [M]
// LeetCode spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_map<int, bool>> visited;
        int i = 0, j = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans;
        bool isGoingUp = false;
        while(ans.size() < n * m) {
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            if(i - 1 < 0 || visited[i-1][j]) isGoingUp = false;
            if(!isGoingUp && j + 1 < m && !visited[i][j + 1]) {
                j += 1;
            } else if(i + 1 < n && !visited[i+1][j]) {
                i += 1;
            } else if(j - 1 >= 0 && !visited[i][j-1]) {
                j -= 1;
            } else if(i - 1 >=0 && !visited[i-1][j]) {
                i -= 1;
                isGoingUp = true;
            }
        }
        return ans;
    }
};