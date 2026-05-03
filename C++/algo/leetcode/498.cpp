// 498. Diagonal Traverse [M]
// LeetCode diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                dict[i + j].push_back(mat[i][j]);
            }
        }
        for(int idx = 0; idx < m + n; idx ++) {
            auto& vec = dict[idx];
            if(idx % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            for(auto item : vec) {
                ans.push_back(item);
            }
        }
        return ans;
    }
};