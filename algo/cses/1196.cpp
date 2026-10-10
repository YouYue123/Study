#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Node {
    ll idx;
    ll cost;
    bool operator > (const Node& other) const {
        return cost > other.cost;
    }
};
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector<pair<ll, ll>>());
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.emplace(1, 0);
    vector dist(n + 1, priority_queue<ll>());
    dist[1].push(0); 
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(dist[cur.idx].size() >= k && dist[cur.idx].top() < cur.cost) continue;
        for(auto& [nxt_idx, cost] : g[cur.idx]) {
            ll nxt_cost = cost + cur.cost;
            if(dist[nxt_idx].size() >= k && dist[nxt_idx].top() <= nxt_cost) continue;
            dist[nxt_idx].push(nxt_cost);
            while(dist[nxt_idx].size() > k) dist[nxt_idx].pop();
            pq.emplace(nxt_idx, nxt_cost);
        }
    }
    vector<ll> ans;
    assert(dist[n].size() == k);
    while(!dist[n].empty()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto item : ans) cout << item << " ";
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}