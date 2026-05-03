// 934. Shortest Bridge [M]
// LeetCode shortest-bridge

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Helper function to perform DFS and mark the first island
        auto dfs = [&](int i, int j, auto&& dfs) {
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
            grid[i][j] = 2; // Mark as part of the first island
            q.push({i, j}); // Add to queue for BFS
            for (auto [di, dj] : directions) {
                dfs(i + di, j + dj, dfs);
            }
        };
        
        // Find and mark the first island
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, dfs);
                    found = true;
                }
            }
        }
        
        // Perform BFS to find the shortest path to the second island
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 2) {
                        if (grid[nx][ny] == 1) return steps; // Found the second island
                        grid[nx][ny] = 2; // Mark water as visited
                        q.push({nx, ny});
                    }
                }
            }
            ++steps;
        }
        return steps; // Should never reach here given problem constraints
    }
};