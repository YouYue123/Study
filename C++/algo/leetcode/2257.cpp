// 2257. Count Unguarded Cells in the Grid [M]
// LeetCode count-unguarded-cells-in-the-grid

class Solution {
    static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector guarded(m, vector<int8_t>(n));
        for (auto& g : guards) {
            guarded[g[0]][g[1]] = -1;
        }
        for (auto& w : walls) {
            guarded[w[0]][w[1]] = -1;
        }
        for (auto& g : guards) {
            for (auto& [dx, dy] : DIRS) {
                int x = g[0] + dx, y = g[1] + dy;
                while (0 <= x && x < m && 0 <= y && y < n && guarded[x][y] != -1) {
                    guarded[x][y] = 1;
                    x += dx;
                    y += dy;
                }
            }
        }
        int ans = 0;
        for (auto& row : guarded) {
            ans += ranges::count(row, 0);
        }
        return ans;
    }
};