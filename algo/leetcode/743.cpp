#include <bits/stdc++.h>
using namespace std;

// 743. Network Delay Time [M]
// LeetCode network-delay-time

int constexpr INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int time;
};
struct Node {
    int id;
    int time;
    bool operator >(const Node& other) const {
        return time < other.time;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector g(n + 1, vector<Edge>());
        for(auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            g[u].emplace_back(v, w);
        }
        vector<int> dist(n + 1, INF);
        priority_queue<Node, vector<Node>, greater<>> pq;
        pq.emplace(k, 0);
        dist[k] = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            for(auto nxt : g[cur.id]) {
                int nxt_id = nxt.to;
                int nxt_time = nxt.time + cur.time;
                if(dist[nxt_id] <= nxt_time) continue;
                dist[nxt_id] = nxt_time;
                pq.emplace(nxt_id, nxt_time);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            ans = max(ans, dist[i]);
        }
        return ans == INF ? -1 : ans;
    }
};