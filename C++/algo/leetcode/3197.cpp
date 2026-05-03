// 3197. Find the Minimum Area to Cover All Ones II [H]
// LeetCode find-the-minimum-area-to-cover-all-ones-ii

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    // https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
    int minimumArea (const vector<vector<int>>& grid, int u, int d, int l , int r) const {
        int minI = INF, maxI = -INF;
        int minJ = INF, maxJ = -INF;
        bool valid = false;
        for(int i = u; i < d; i ++) {
            for(int j = l; j < r; j ++) {
                if(grid[i][j] == 1) {
                    minI = min(minI, i);
                    maxI = max(maxI, i);
                    minJ = min(minJ, j);
                    maxJ = max(maxJ, j);
                    valid = true;
                }
            }
        }
        return valid ? (maxI - minI + 1) * (maxJ - minJ + 1) : 0;
    };
     vector<vector<int>> rotate(const vector<vector<int>>& grid) const {
        int m = grid.size(), n = grid[0].size();
        vector b(n, vector<int>(m, 0));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n ; j ++) {
                b[j][m - 1 - i] = grid[i][j];
            }
        }
        return b;
    };
    int solve (const vector<vector<int>>& grid) const {
        int m = grid.size(), n = grid[0].size();
        int ans = INF;
        if(m >= 3) {
            for(int i = 1; i < m; i ++) {
                for(int j = i + 1; j < m; j ++) {
                    // 3 horizontal
                    int area = minimumArea(grid, 0, i, 0, n);
                    area += minimumArea(grid, i, j, 0, n);
                    area += minimumArea(grid, j, m, 0, n);
                    ans = min(ans, area);
                }
            }
        }
        if(m >= 2 && n >= 2) {
            for(int i = 1; i < m; i ++) {
                for(int j = 1; j < n; j ++) {
                    // T
                    int area = minimumArea(grid, 0, i, 0, n);
                    area += minimumArea(grid, i, m, 0, j);
                    area += minimumArea(grid, i, m, j, n);
                    ans = min(ans, area);
                    // Up-sidedown T
                    area = minimumArea(grid, 0, i, 0, j);
                    area += minimumArea(grid, 0, i, j, n);
                    area += minimumArea(grid, i, m, 0, n);
                    ans = min(ans, area);
                }
            }
        }
        return ans;
    };
    int minimumSum(vector<vector<int>>& grid) {
        return min(solve(grid), solve(rotate(grid)));
    }
};