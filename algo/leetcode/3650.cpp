#include <bits/stdc++.h>
using namespace std;

// 3650. Minimum Cost Path with Edge Reversals [M]
// LeetCode minimum-cost-path-with-edge-reversals

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int dist;
    int node;
    bool operator < (const Node& other) const {
        return dist < other.dist;
    }
    bool operator > (const Node& other) const {
        return dist > other.dist;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector<vector<pair<int, int>>> dict(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dict[u].push_back({v, w});
            dict[v].push_back({u, 2 * w});
        }
        vector minDist(n, INF);
        pq.emplace(0, 0);
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.node == n - 1) return cur.dist;
            for(auto& nxt : dict[cur.node]) {
                int v = nxt.first, w = nxt.second;
                if(cur.dist + w < minDist[v]) {
                    minDist[v] = cur.dist + w;
                    pq.emplace(cur.dist + w, v);
                }
            }
        }
        return -1;
    }
};