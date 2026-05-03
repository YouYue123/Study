// 2352. Equal Row and Column Pairs [M]
// LeetCode equal-row-and-column-pairs

class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        unordered_map<int, string> rowCode;
        unordered_map<int, string> colCode;
        int n = grid.size();
        for(int i = 0; i < n;i ++) {
            for(int j = 0; j < n; j ++) {
                rowCode[i] += " " + to_string(grid[i][j]);
                colCode[j] += " " + to_string(grid[i][j]);
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                // cout << rowCode[i] << " " << colCode[j] << endl;
                if(rowCode[i] == colCode[j]) ans += 1;
            }
        }
        return ans;
    }
};