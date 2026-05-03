// 361. Bomb Enemy [M]
// LeetCode bomb-enemy

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        vector<vector<int>> up(m, vector<int>(n, 0));
        vector<vector<int>> down(m, vector<int>(n, 0));

        // Preprocess rows: left and right
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') continue;
                if (grid[i][j] == 'E') left[i][j] = 1;
                if (j > 0) left[i][j] += left[i][j - 1];
            }
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 'W') continue;
                if (grid[i][j] == 'E') right[i][j] = 1;
                if (j < n - 1) right[i][j] += right[i][j + 1];
            }
        }

        // Preprocess columns: up and down
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') continue;
                if (grid[i][j] == 'E') up[i][j] = 1;
                if (i > 0) up[i][j] += up[i - 1][j];
            }
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == 'W') continue;
                if (grid[i][j] == 'E') down[i][j] = 1;
                if (i < m - 1) down[i][j] += down[i + 1][j];
            }
        }

        // Find max enemies killed by placing a bomb at each empty cell
        int maxKills = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    int total = 0;
                    // Count enemies in four directions, subtract overlap
                    if (j > 0) total += left[i][j - 1];
                    if (j < n - 1) total += right[i][j + 1];
                    if (i > 0) total += up[i - 1][j];
                    if (i < m - 1) total += down[i + 1][j];
                    maxKills = max(maxKills, total);
                }
            }
        }

        return maxKills;
    }
};
