#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll to;
    ll len;
    bool operator<(const Item& other) const {
        return len < other.len;
    }
    bool operator>(const Item& other) const {
        return len > other.len;
    }
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<Item>());
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    
    vector dist(n + 1, INF);
    priority_queue<Item, vector<Item>, greater<>> pq;
    pq.emplace(1, 0);
    dist[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.to] < cur.len) continue;
        for(auto& nxt : g[cur.to]) {
            ll nxt_len = nxt.len + cur.len;
            if(dist[nxt.to] <= nxt_len) continue;
            dist[nxt.to] = nxt_len;
            pq.emplace(nxt.to, nxt_len);
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}