// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance [M]
// LeetCode find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

int constexpr INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int weight;
};
struct Node {
    int id;
    int weight;
    bool operator >(const Node& other) const {
        return weight > other.weight;
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector g(n, vector<Edge> ());
        for(auto& e : edges) {
            int from = e[0], to = e[1] , weight = e[2];
            g[from].emplace_back(to, weight);
            g[to].emplace_back(from, weight);
        }
        auto dijkstra = [&] (this auto&& dfs, int i) {
            vector<int> dist(n, INF);
            priority_queue<Node, vector<Node>, greater<>> pq;
            pq.emplace(i, 0);
            dist[i] = 0;
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                if(dist[cur.id] < cur.weight) continue;
                for(auto& nxt : g[cur.id]) {
                    int nxt_id = nxt.to;
                    int nxt_weight = cur.weight + nxt.weight;
                    if(dist[nxt_id] <= nxt_weight) continue;
                    dist[nxt_id] = nxt_weight;
                    pq.emplace(nxt_id, nxt_weight);
                }
            }
            return dist;
        };
        int min_reach = INF;
        int ans = -1;
        for(int i = 0; i < n; i ++) {
            // cout << "for i : " << i << endl;
            auto dist = dijkstra(i);
            int reach_cnt = 0;
            for(int j = 0; j < n; j ++) {
                if(i == j) continue;
                if(dist[j] <= distanceThreshold) reach_cnt += 1;
            }
            // cout << reach_cnt << endl;
            if(min_reach >= reach_cnt) {
                min_reach = reach_cnt;
                ans = i;
            }
        }
        return ans;
    }
};