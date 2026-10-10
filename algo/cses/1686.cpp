#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector weights(n + 1, 0LL);
    for(int i = 1; i <= n; i ++) cin >> weights[i];
    vector g(n + 1, vector<int>());
    vector rev_g(n + 1, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }

    stack<int> st;
    vector visit(n + 1, false);
    auto dfs_1 = [&] (auto& dfs, int u) {
        if(visit[u]) return;
        visit[u] = true;
        for(auto v : g[u]) dfs(dfs, v);
        st.push(u);
    };

    for(int u = 1; u <= n; u ++) dfs_1(dfs_1, u);
    
    vector scc_ids(n + 1, 0);
    int scc_id = 1;
    auto dfs_2 = [&] (auto& dfs, int u) {
        if(scc_ids[u] != 0) return;
        scc_ids[u] = scc_id;
        for(auto v : rev_g[u]) dfs(dfs, v);
    };
    while(!st.empty()) {
        auto u = st.top(); st.pop();
        if(scc_ids[u] != 0) continue;
        dfs_2(dfs_2, u);
        scc_id += 1;
    }

    vector new_g(scc_id, set<int>());
    vector scc_weights(scc_id, 0LL);
    for(int u = 1; u <= n; u ++) {
        int u_scc_id = scc_ids[u];
        scc_weights[u_scc_id] += weights[u];
        for(auto v : g[u]) {
            if(scc_ids[u] != scc_ids[v]) {
                int v_scc_id = scc_ids[v];
                new_g[u_scc_id].insert(v_scc_id);
            }
        }
    }

    vector dist(scc_id, 0LL);
    ll ans = 0;
    for(int u = 1; u < scc_id; u ++) {
        dist[u] = max(dist[u], scc_weights[u]);
        ans = max(ans, dist[u]);
        for(auto v : new_g[u]) {
            dist[v] = max(dist[v], dist[u] + scc_weights[v]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}