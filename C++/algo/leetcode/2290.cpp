#include <bits/stdc++.h>
using namespace std;

// 2290. Minimum Obstacle Removal to Reach Corner [H]
// LeetCode minimum-obstacle-removal-to-reach-corner

struct Item {
    int x;
    int y;
    int dist;
    // bool operator<(const Item& other) const {
    //     return dist < other.dist;
    // }
    bool operator>(const Item& other) const {
        return dist > other.dist;
    }
};
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        deque<Item> q;
        vector dist(m, vector(n, INF));
        q.emplace_back(0, 0, 0);
        dist[0][0] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            if(cur.x == m - 1 && cur.y == n - 1) {
                return cur.dist;
            }
            for(auto& dir : dirs) {
                int n_x = cur.x + dir.first, n_y = cur.y + dir.second;
                if(n_x < 0 || n_x >= m || n_y < 0 || n_y >= n) continue;
                int n_dist = cur.dist + grid[n_x][n_y];
                if(dist[n_x][n_y] <= n_dist) continue;
                dist[n_x][n_y] = n_dist;
                if(grid[n_x][n_y] == 1) {
                    q.emplace_back(n_x, n_y, n_dist);
                } else {
                    q.emplace_front(n_x, n_y, n_dist);
                }
            }
        }
        // priority_queue<Item, vector<Item>, greater<>> pq;
        // vector dist(m, vector(n, INF));
        // pq.emplace(0, 0, 0);
        // dist[0][0] = 0;
        // while(!pq.empty()) {
        //     auto cur = pq.top();
        //     pq.pop();
        //     if(cur.x == m - 1 && cur.y == n - 1) {
        //         return cur.dist;
        //     }
        //     for(auto& dir : dirs) {
        //         int n_x = cur.x + dir.first, n_y = cur.y + dir.second;
        //         if(n_x < 0 || n_x >= m || n_y < 0 || n_y >= n) continue;
        //         int n_dist = cur.dist + grid[n_x][n_y];
        //         if(dist[n_x][n_y] <= n_dist) continue;
        //         dist[n_x][n_y] = n_dist;
        //         pq.emplace(n_x, n_y, n_dist);
        //     }
        // }
        return -1;
    }
};
