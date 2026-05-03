#include <bits/stdc++.h>
using namespace std;

// 3212. Count Submatrices With Equal Frequency of X and Y [M]
// LeetCode count-submatrices-with-equal-frequency-of-x-and-y

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector pre_sum_x(m, vector(n, 0));
        vector pre_sum_y(m, vector(n, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                pre_sum_x[i][j] = (j > 0 ? pre_sum_x[i][j - 1] : 0) + (grid[i][j] == 'X' ? 1 : 0);
                pre_sum_y[i][j] = (j > 0 ? pre_sum_y[i][j - 1] : 0) + (grid[i][j] == 'Y' ? 1 : 0);
            }
        }
        int ans = 0;
        for(int c = 0; c < n; c ++) {
            int sum_x = 0, sum_y = 0;
            for(int r = 0; r < m; r ++) {
                sum_x += pre_sum_x[r][c];
                sum_y += pre_sum_y[r][c];
                // cout << r << " " << c << endl;
                // cout << "sum_x: " << sum_x << " sum_y: " << sum_y << endl; 
                if(sum_x > 0 && sum_x == sum_y) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};