// 3128. Right Triangles [M]
// LeetCode right-triangles

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowCnt(m, 0);
        vector<long long> colCnt(n, 0);
        for(int i = 0; i < m; i ++) {
            for (int j = 0 ;j < n; j ++) {
                if(grid[i][j] == 1) {
                    rowCnt[i] += 1;
                    colCnt[j] += 1;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < m; i ++) {
            for(int j = 0 ; j < n; j ++) {
                if(grid[i][j] == 1) {
                    if(rowCnt[i] - 1 > 0 && colCnt[j] - 1 > 0) {
                        ans += (rowCnt[i] - 1) * (colCnt[j] - 1);
                    }
                }
            }
        }
        return ans;
    }
};