#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
struct Node {
    ll idx;
    ll cost;
    bool operator > (const Node& other) const {
        return cost > other.cost;
    }
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<pair<ll, ll>>());
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.emplace(1, 0);
    vector min_price(n + 1, INF);
    vector cnt(n + 1, 0LL);
    vector min_num(n + 1, INF);
    vector max_num(n + 1, 0LL);
    min_price[1] = 0;
    cnt[1] = 1;
    min_num[1] = 0;
    max_num[1] = 0;
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(min_price[cur.idx] < cur.cost || cur.idx == n) continue;
        for(auto& [nxt_idx, price] : g[cur.idx]) {
            ll nxt_cost = price + cur.cost;
            if(nxt_cost < min_price[nxt_idx]) {
                min_price[nxt_idx] = nxt_cost;
                cnt[nxt_idx] = cnt[cur.idx];
                min_num[nxt_idx] = min_num[cur.idx] + 1;
                max_num[nxt_idx] = max_num[cur.idx] + 1;
                pq.emplace(
                    nxt_idx, 
                    nxt_cost
                );
            } else if(nxt_cost == min_price[nxt_idx]){
                cnt[nxt_idx] = (cnt[cur.idx] + cnt[nxt_idx]) % MOD;
                min_num[nxt_idx] = min(min_num[nxt_idx], min_num[cur.idx] + 1);
                max_num[nxt_idx] = max(max_num[nxt_idx], max_num[cur.idx] + 1);
            }
        }
    }
    cout << min_price[n] << " " << cnt[n] << " " << min_num[n] << " " << max_num[n]  << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}