// 3070. Count Submatrices with Top-Left Element and Sum Less Than k [M]
// LeetCode count-submatrices-with-top-left-element-and-sum-less-than-k

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector pre_sum(m, vector(n, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                pre_sum[i][j] = (j > 0 ? pre_sum[i][j - 1] : 0) + grid[i][j];
            }
        }
        int ans = 0;
        for(int c = 0; c < n; c ++) {
            int sum = 0;
            for(int r = 0; r < m; r ++) {
                sum += pre_sum[r][c];
                if(sum > k) break;
                // cout << r << " " << c << endl;
                // cout << sum << endl;
                ans += 1;
            }
        }
        return ans;
    }
};