// 490. The Maze [M]
// LeetCode the-maze

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector visited(m, vector(n, false));
        using pii = pair<int, int>;
        vector<pii> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        auto dfs = [&](this auto&& dfs, int x, int y) {
            if(x < 0 || x >= m || y < 0 || y >= n) return false;
            if(visited[x][y]) return false;
            if(x == destination[0] && y == destination[1]) return true;
            visited[x][y] = true;
            for(auto& d : dirs) {
                int nx = x, ny = y;
                while(nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == 0) {
                    nx = nx + d.first;
                    ny = ny + d.second;
                }
                nx -= d.first, ny -= d.second;
                if(dfs(nx, ny)) return true;
            }
            return false;
        };
        return dfs(start[0], start[1]);
    }
};