// 317. Shortest Distance from All Buildings [H]
// LeetCode shortest-distance-from-all-buildings

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return -1;
        int cols = grid[0].size();
        
        int total_buildings = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) total_buildings++;
            }
        }
        
        if (total_buildings == 0) return 0;
        
        vector<vector<int>> distanceSum(rows, vector<int>(cols, 0));
        vector<vector<int>> reachCount(rows, vector<int>(cols, 0));
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    queue<pair<int, int>> q;
                    
                    for (const auto& dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 0 && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                            distanceSum[ni][nj] += 1;
                            reachCount[ni][nj] += 1;
                        }
                    }
                    
                    int current_distance = 1;
                    while (!q.empty()) {
                        int size = q.size();
                        current_distance++;
                        for (int k = 0; k < size; ++k) {
                            auto [x, y] = q.front();
                            q.pop();
                            
                            for (const auto& dir : directions) {
                                int nx = x + dir.first;
                                int ny = y + dir.second;
                                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0 && !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                    distanceSum[nx][ny] += current_distance;
                                    reachCount[nx][ny]++;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0 && reachCount[i][j] == total_buildings) {
                    ans = min(ans, distanceSum[i][j]);
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};