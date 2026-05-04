#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
struct Coord {
    int x;
    int y;
    int cost;
    bool operator > (const Coord& other) const {
        return cost > other.cost;
    };
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector g(
            m, 
            vector(
                n,
                vector<Coord>()
            )
        );
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                if(i + 1 < m)  g[i][j].emplace_back(i + 1, j, grid[i][j] != 3);
                if(i - 1 >= 0) g[i][j].emplace_back(i - 1, j, grid[i][j] != 4);
                if(j + 1 < n)  g[i][j].emplace_back(i, j + 1, grid[i][j] != 1);
                if(j - 1 >= 0) g[i][j].emplace_back(i, j - 1, grid[i][j] != 2);
            }
        }
        priority_queue<Coord, vector<Coord>, greater<>> pq;
        vector dist(m, vector(n, INF));
        pq.emplace(0, 0, 0);
        dist[0][0] = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.x == m - 1 && cur.y == n - 1) {
                return cur.cost;
            }
            for(auto& nxt : g[cur.x][cur.y]) {
                int nxt_cost = cur.cost + nxt.cost;
                if(dist[nxt.x][nxt.y] <= nxt_cost) continue;
                dist[nxt.x][nxt.y] = nxt_cost;
                pq.emplace(nxt.x, nxt.y, nxt_cost);
            }
        }
        return -1;
    }
};