// 2536. Increment Submatrices by One [M]
// LeetCode increment-submatrices-by-one

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n + 1, 0));
        for(auto& q : queries) {
            int ar = q[0], ac = q[1];
            int br = q[2], bc = q[3];
            for(int r = ar; r <= br; r ++) {
                diff[r][ac] += 1;
                diff[r][bc + 1] -= 1;
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++) {
            int curSum = 0;
            for(int j = 0; j < n; j ++) {
                curSum += diff[i][j];
                ans[i][j] = curSum;
            }
        }
        return ans;
    }
};