// 1351. Count Negative Numbers in a Sorted Matrix [E]
// LeetCode count-negative-numbers-in-a-sorted-matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m - 1, j = 0;
        int ans = 0;
        while(i >= 0 && j < n) {
            if(grid[i][j] < 0) {
                ans += (n - j);
                i -= 1;
            } else {
                j += 1;
            }
        }
        return ans;
    }
};