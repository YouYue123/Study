#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Node {
    ll idx;
    ll cost;
    ll use_cnt;
    bool operator> (const Node& other) const {
        return cost > other.cost;
    };
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<Node>());
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    priority_queue<Node, vector<Node>, greater<>> pq;
    vector dist(n + 1, vector(2, INF));
    pq.emplace(1, 0, 0);
    dist[1][0] = 0;
    ll ans = INF;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(cur.cost > dist[cur.idx][cur.use_cnt]) continue;
        if(cur.idx == n) continue;
        for(auto& [nxt_idx, cost, _] : g[cur.idx]) {
            if(cur.use_cnt == 0) {
                ll nxt_cost = cost / 2 + cur.cost;
                if(nxt_cost < dist[nxt_idx][1]) {
                    // cout << "use " << " nxt_idx: " << nxt_idx << " nxt_cost: " << nxt_cost << endl;
                    dist[nxt_idx][1] = nxt_cost;
                    pq.emplace(nxt_idx, nxt_cost, 1);
                }
            }
            ll nxt_cost = cost + cur.cost;
            if(nxt_cost < dist[nxt_idx][cur.use_cnt]) {
                dist[nxt_idx][cur.use_cnt] = nxt_cost;
                pq.emplace(nxt_idx, nxt_cost, cur.use_cnt);
            }
        }
    }

    cout << dist[n][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}