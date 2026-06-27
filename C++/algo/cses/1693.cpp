#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<pair<int, int>>());
    vector in_degree(n + 1, 0);
    vector out_degree(n + 1, 0);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b, i);
        out_degree[a] += 1;
        in_degree[b] += 1;
    }
    bool valid = true;
    for(int u = 1; u <= n; u ++) {
        if(u == 1) {
            if(out_degree[u] - in_degree[u] != 1) {
                valid = false;
                break;
            }
        } else if(u == n) {
            if(in_degree[u] - out_degree[u] != 1) {
                valid = false;
                break;
            }
        } else {
            if(in_degree[u] != out_degree[u]) {
                valid = false;
                break;
            }
        }
    }
    if(!valid) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    // vector<int> cur(n + 1, 0);
    vector ptr(n + 1, 0);
    vector visit(m, false);
    vector<int> ans;
    // stack<int> st;

    auto dfs = [&] (auto&& dfs, int u) -> void {
        while(ptr[u] < g[u].size()) {
            auto [v, edge_id] = g[u][ptr[u]];
            ptr[u] += 1;
            if(visit[edge_id]) continue;
            visit[edge_id] = true;
            dfs(dfs, v);
            ans.push_back(v);
        }
    };
    dfs(dfs, 1);
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    if(ans.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(auto item : ans) cout << item << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}