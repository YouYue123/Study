// 778. Swim in Rising Water [H]
// LeetCode swim-in-rising-water

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int x;
    int y;
    int time;
    bool operator> (const Node& other) {
        return time > other.time;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector dist(n, vector(n, INF));
        pq.emplace(0, 0, grid[0][0]);
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.x == n - 1 && cur.y == n - 1) break;
            for(auto& dir : dirs) {
                int nx = cur.x + dir.first, ny = cur.y + dir.second;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int nTime = max(cur.time, grid[nx][ny]);
                if(nTime >= dist[nx][ny]) continue;
                dist[nx][ny] = nTime;
                pq.emplace(nx, ny, nTime);
            }
        }
        return dist[n - 1][n - 1] == INF ? 0 : dist[n - 1][n - 1];
    }
};