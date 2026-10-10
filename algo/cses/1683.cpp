#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<ll>());
    vector rev_g(n + 1, vector<ll>());
    for(int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }
    stack<ll> st;
    vector visit(n + 1, false);
    auto dfs_1 = [&] (auto&& dfs, int u) -> void {
        if(visit[u]) return;
        visit[u] = true;
        for(auto& v : g[u]) dfs(dfs, v);
        st.push(u);
    };
    for(int i = 1; i <= n; i ++) {
        if(visit[i]) continue;
        dfs_1(dfs_1, i);
    }
    vector scc_ids(n + 1, 0);
    int scc_id = 1;
    auto dfs_2 = [&] (auto&& dfs, int u) -> void {
        if(scc_ids[u] != 0) return;
        scc_ids[u] = scc_id;
        for(auto& v : rev_g[u]) dfs(dfs, v);
    };
    while(!st.empty()) {
        auto u = st.top(); st.pop();
        if(scc_ids[u] != 0) continue;
        dfs_2(dfs_2, u);
        scc_id += 1;
    }
    cout << scc_id - 1 << endl;
    for(int i = 1; i <= n; i ++) cout << scc_ids[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}