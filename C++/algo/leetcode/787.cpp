// 787. Cheapest Flights Within K Stops [M]
// LeetCode cheapest-flights-within-k-stops

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int idx;
    int price;
    int stop;
    bool operator > (const Node& other) {
        return price > other.price;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> g;
        for(auto& f : flights) {
            int from = f[0], to = f[1], price = f[2];
            g[from].push_back({ to, price });
        }
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector dist(n, vector(k + 2, INF));
        dist[src][0] = 0;
        pq.emplace(src, 0, 0);
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.idx == dst) break;
            for(auto& nxt : g[cur.idx]) {
                int nxtIdx = nxt.first;
                int nxtPrice = cur.price + nxt.second;
                int nxtStop = cur.stop + 1;
                if(nxtStop > k + 1) continue;
                if(nxtPrice >= dist[nxtIdx][nxtStop]) continue;
                dist[nxtIdx][nxtStop] = nxtPrice;
                pq.emplace(nxtIdx, nxtPrice, nxtStop);
            }
        }
        int ans = INF;
        for(int i = 0; i <= k + 1; i ++) {
            // cout << dist[dst][i] << endl;
            ans = min(ans, dist[dst][i]);
        }
        return ans == INF ? -1 : ans;
    }
};