#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
    ll from;
    ll to;
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<ll>());
    vector in_order(n + 1, 0);
    vector dist(n + 1, -INF);
    vector parent(n + 1, 0);
    for(int i = 0; i < m; i ++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in_order[b] += 1;
    }
    vector<ll> topo;
    queue<ll> q;
    for(int i = 1; i <= n; i ++) {
        if(in_order[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for(int nxt : g[cur]) {
            in_order[nxt] -= 1;
            if(in_order[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    dist[1] = 0;
    for(int cur : topo) {
        if(dist[cur] == -INF) continue;
        for(int nxt: g[cur]) {
            if(dist[cur] + 1 > dist[nxt]) {
                dist[nxt] = dist[cur] + 1;
                parent[nxt] = cur; 
            }
        }
    }


    if(dist[n] == -INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<ll> ans;
        ll cur = n;
        while(cur != 1) {
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto item : ans) cout << item << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}