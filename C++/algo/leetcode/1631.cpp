// 1631. Path With Minimum Effort [M]
// LeetCode path-with-minimum-effort

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int x;
    int y;
    int maxEffort;
    bool operator > (const Node& other) {
        return maxEffort > other.maxEffort;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        // queue<Node> q;
        // q.emplace(0, 0, 0);
        // while(!q.empty()) {
        //     auto cur = q.front();
        //     q.pop();
        //     for(auto& d : dirs) {
        //         int nx = cur.x + d.first, ny = cur.y + d.second;
        //         if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        //         if(visited[nx][ny]) continue;
        //         visited[nx][ny] = true;
        //         dist[nx][ny] = min(dist[nx][ny], abs(heights[cur.x][cur.y] - heights[nx][ny]));
        //         q.emplace(nx, ny);
        //     }
        // }
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector dist(m, vector(n, INF));
        pq.emplace(0, 0, 0);
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.x == m - 1 && cur.y == n - 1) break;
            for(auto& d: dirs) {
                int nx = cur.x + d.first, ny = cur.y + d.second;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nEffort = max(cur.maxEffort, abs(heights[nx][ny] - heights[cur.x][cur.y]));
                if(nEffort >= dist[nx][ny]) continue;
                dist[nx][ny] = nEffort;
                pq.emplace(nx, ny, nEffort);
            }
        }
        return dist[m - 1][n - 1] == INF ? 0 : dist[m - 1][n - 1];
    }
};