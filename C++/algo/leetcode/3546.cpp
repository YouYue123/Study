#include <bits/stdc++.h>
using namespace std;

// 3546. Equal Sum Grid Partition I [M]
// LeetCode equal-sum-grid-partition-i

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> row_sum(m, 0);
        vector<long long> col_sum(n, 0);
        for(int i = 0; i < m; i ++) {
            long long sum = 0;
            for(int j = 0; j < n; j ++) {
                sum += grid[i][j];
            }
            row_sum[i] = (i > 0 ? row_sum[i - 1] : 0) + sum;
        }
        for(int j = 0; j < n; j ++) {
            long long sum = 0;
            for(int i = 0; i < m; i ++) {
                sum += grid[i][j];
            }
            col_sum[j] = (j > 0 ? col_sum[j - 1] : 0) + sum;
        }
        for(int row_cut = 0; row_cut < m - 1; row_cut ++) {
            long long first_half = row_sum[row_cut];
            long long second_half = row_sum.back() - first_half;
            // cout << "row: " << first_half << " " << second_half << endl;
            if(first_half == second_half) return true;
        }
        for(int col_cut = 0; col_cut < n - 1; col_cut ++) {
            long long first_half = col_sum[col_cut];
            long long second_half = col_sum.back() - first_half;
            if(first_half == second_half) return true;
        }
        return false;
    }
};