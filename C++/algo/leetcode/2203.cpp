// 2203. Minimum Weighted Subgraph With the Required Paths [H]
// LeetCode minimum-weighted-subgraph-with-the-required-paths

long long constexpr INF = 0x3f3f3f3f3f3f;
struct Edge {
    int to;
    long long weight;
};
struct Node {
    int id;
    long long dist;
    bool operator >(const Node& other) const {
        return dist > other.dist;
    }
};
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector g(n, vector<Edge> ());
        vector rev_g(n, vector<Edge>());
        for(auto& e : edges) {
            int from = e[0], to = e[1], weight = e[2];
            g[from].emplace_back(to, weight);
            rev_g[to].emplace_back(from, weight);
        }
        auto dijkstra = [&] (vector<vector<Edge>>& g, int src) {
            vector<long long> dist(n, INF);  
            priority_queue<Node, vector<Node>, greater<>> pq;
            dist[src] = 0;
            pq.emplace(src, 0);
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                if (cur.dist > dist[cur.id]) continue;
                for(auto nxt : g[cur.id]) {
                    long long nxt_id = nxt.to;
                    long long nxt_dist = nxt.weight + cur.dist;
                    if(dist[nxt_id] <= nxt_dist) continue;
                    dist[nxt_id] = nxt_dist;
                    pq.emplace(nxt_id, nxt_dist);
                }
            }
            return dist;
        };
        long long ans = INF;
        auto dist_arr_1 = dijkstra(g, src1);
        auto dist_arr_2 = dijkstra(g, src2);
        auto dist_arr_3 = dijkstra(rev_g, dest);
        for(int i = 0; i < n; i ++) {
            if (dist_arr_1[i] == INF || dist_arr_2[i] == INF || dist_arr_3[i] == INF) continue;
            ans = min(
                ans,
                dist_arr_1[i] + dist_arr_2[i] + dist_arr_3[i]
            );
        }
        return ans >= INF ? -1 : ans;
    }
};