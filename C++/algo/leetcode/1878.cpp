// 1878. Get Biggest Three Rhombus Sums in a Grid [M]
// LeetCode get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> unique_sums; 
        vector<pair<int, int>> dirs = {
            {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
        };
        // enumerate center point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unique_sums.insert(grid[i][j]);
                for (int k = 1; ; k++) {
                    // Top: (i-k, j), Bottom: (i+k, j), Left: (i, j-k), Right: (i, j+k)
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n) break;

                    int sum = 0;
                    int r = i - k, c = j; // Start from Top Point
                                    
                    for (auto& dir : dirs) {
                        for (int step = 0; step < k; step++) {
                            sum += grid[r][c];
                            r += dir.first;
                            c += dir.second;
                        }
                    }
                    unique_sums.insert(sum);
                }
                
                while(unique_sums.size() > 3) {
                    unique_sums.erase(unique_sums.begin());
                }
            }
        }

        vector<int> result(unique_sums.rbegin(), unique_sums.rend());
        return result;
    }
};