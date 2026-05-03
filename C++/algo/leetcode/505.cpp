// 505. The Maze II [M]
// LeetCode the-maze-ii

struct Move {
    int x;
    int y;
    int dist;
    bool operator < (const Move& other) const {
        return dist < other.dist;
    };
    bool operator > (const Move& other) const {
        return dist > other.dist;
    }
};
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        priority_queue<Move, vector<Move>, greater<>> q;
        q.emplace(start[0], start[1], 0);
        vector distDict(m, vector(n, INF));
        vector<pair<int, int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();
            if (cur.dist > distDict[cur.x][cur.y]) continue;
            // cout << cur.x << " " << cur.y << " " << cur.dist << endl;
            if(cur.x == destination[0] && cur.y == destination[1]) return cur.dist;
            for(auto& dir : dirs) {
                int x = cur.x, y = cur.y, dist = cur.dist;
                while(x + dir.first < m && x + dir.first >= 0 && y + dir.second < n && y + dir.second >= 0) {
                    if(maze[x + dir.first][y + dir.second] == 1) break;
                    x += dir.first;
                    y += dir.second;
                    dist += 1;
                }
                // cout << x << " " << y << endl;
                if(dist < distDict[x][y]) {
                    distDict[x][y] = dist;
                    q.emplace(x, y, dist);
                }
            }
        }
        return -1;
    }
};