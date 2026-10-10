#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
    int to;
    int edge_id;
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector degree(n + 1, 0);
    vector g(n + 1, vector<Edge>());
    vector edge_cnt(n + 1, 0);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
        degree[a] += 1;
        degree[b] += 1;
    }
    int odd_cnt = 0;
    for(int u = 1; u <= n; u ++) {
        if(degree[u] % 2 == 1) odd_cnt += 1;
    }
    if(odd_cnt != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> ans;
    vector edge_visit(m + 1, false);
    auto hierholzer = [&] (auto&& dfs, int u) -> void {
        while(edge_cnt[u] < g[u].size()) {
            auto [v, edge_id] = g[u][edge_cnt[u]];
            edge_cnt[u] += 1;
            if(edge_visit[edge_id]) continue;
            edge_visit[edge_id] = true;
            dfs(dfs, v);
        }
        ans.push_back(u);
    };
    hierholzer(hierholzer, 1);
    if(ans.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
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