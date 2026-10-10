#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector g(n + 1, 0);
    for(int i = 1; i <= n; i ++)  cin >> g[i];
    vector color(n + 1, 0);
    vector dist_to_cycle(n + 1, 0);
    vector cycle_ids(n + 1, 0);
    vector<int> cycle_len;
    vector<int> path;
    auto dfs = [&] (auto& dfs, int u) -> void {
        if(color[u] == 1) {
            int prev_u_idx = -1;
            for(int k = path.size() - 1; k >= 0; k --) {
                if(path[k] == u) {
                    prev_u_idx = k;
                    break;
                }
            }
            int cycle_idx = cycle_len.size();
            int len = path.size() - prev_u_idx;
            cycle_len.push_back(len);
            for(int k = prev_u_idx; k < path.size(); k ++) {
                int v = path[k];
                cycle_ids[v] = cycle_idx;
                dist_to_cycle[v] = 0;
            }
            for(int k = prev_u_idx - 1; k >= 0; k --) {
                int v = path[k];
                cycle_ids[v] = cycle_idx;
                dist_to_cycle[v] = prev_u_idx - k;
            }
            return;
        } 
        if(color[u] == 2) {
            for(int k = path.size() - 1; k >= 0; k --) {
                int v = path[k];
                cycle_ids[v] = cycle_ids[u];
                dist_to_cycle[v] = dist_to_cycle[u] + (path.size() - k);
            }
            return;
        }
        color[u] = 1;
        path.push_back(u);
        dfs(dfs, g[u]);
        path.pop_back();
        color[u] = 2;
    };

    for(int i = 1; i <= n; i ++) {
        if(color[i] == 0) dfs(dfs, i);
    }

    for(int i = 1 ; i <= n; i ++) {
        bool on_cycle = dist_to_cycle[i] == -1;
        int cycle_idx = cycle_ids[i];
        if(on_cycle) {
            cout << cycle_len[cycle_idx] << " ";
        } else {
            cout << dist_to_cycle[i] + cycle_len[cycle_idx] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}