#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    ll to;
    ll len;
};
struct Node {
    ll idx;
    ll len;
    bool operator<(const Node& other) const {
        return len < other.len;
    }
    bool operator>(const Node& other) const {
        return len > other.len;
    }
};
struct Query {
    ll from;
    ll to;
};
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector g(n + 1, vector<Edge>());
    vector dist(n + 1, vector(n + 1, INF));
    for (ll i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        if(c < dist[a][b]) {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }
    vector<Query> queries(q);
    for(int i = 0; i < q; i ++) {
        ll a, b;
        cin >> queries[i].from >> queries[i].to;
    }
    for(ll k = 1; k <= n; k ++) {
        for(ll i = 1; i <= n; i ++) {
            if(dist[i][k] == INF) continue;
            for(ll j = 1; j <= n; j ++) {
                ll nd = dist[i][k] + dist[k][j];
                if(nd < dist[i][j]) dist[i][j] = nd;
            }
        }
    }
    // for(int i = 1; i <= n; i ++) {
    //     priority_queue<Node, vector<Node>, greater<>> pq;
    //     pq.emplace(i, 0);
    //     dist[i][i] = 0;
    //     while(!pq.empty()) {
    //         auto cur = pq.top();
    //         pq.pop();
    //         if(dist[i][cur.idx] < cur.len) continue;
    //         for(auto& nxt : g[cur.idx]) {
    //             ll nxt_len = nxt.len + cur.len;
    //             if(dist[i][nxt.to] <= nxt_len) continue;
    //             dist[i][nxt.to] = nxt_len;
    //             pq.emplace(nxt.to, nxt_len);
    //         }
    //     }
    // }
    // cout << "here" << endl;
    for(auto& query : queries) {
        ll ans = dist[query.from][query.to];
        cout << (ans == INF ? -1 : ans) << endl;
    }
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}