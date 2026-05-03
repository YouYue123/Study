// 1198. Find Smallest Common Element in All Rows [M]
// LeetCode find-smallest-common-element-in-all-rows

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> dict;
        int m = mat.size(), n = mat[0].size();
        int ans = INT_MAX;
        for (int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                dict[mat[i][j]] += 1;
            }
        }
        for (int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(dict[mat[i][j]] == m) {
                    ans = min(ans, mat[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};