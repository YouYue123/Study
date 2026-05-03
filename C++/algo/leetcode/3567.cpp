// 3567. Minimum Absolute Difference in Sliding Submatrix [M]
// LeetCode minimum-absolute-difference-in-sliding-submatrix

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m - k + 1; i ++) {
            vector<int> row;
            for(int j = 0; j < n - k + 1; j ++) {
                vector<int> vals;
                for(int p = i; p < i + k; p ++) {
                    for(int q = j; q < j + k; q ++) {
                        vals.push_back(grid[p][q]);
                    }
                }
                int curMin = INT_MAX;
                sort(vals.begin(), vals.end());
                // for(int num : vals) cout << num << " ";
                // cout << endl;
                for(int t = 1; t < (int)vals.size(); t ++) {
                    int diff = abs(vals[t] - vals[t - 1]);
                    if(diff == 0) continue;
                    // cout << diff << endl;
                    // cout << vals[t] << " " << vals[t - 1] << endl;
                    curMin = min(curMin, diff);
                }
                if(curMin == INT_MAX) curMin = 0;
                row.push_back(curMin);
            }
            ans.push_back(row);
        }
        return ans;
    }
};