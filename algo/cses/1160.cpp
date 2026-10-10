#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll constexpr LOG = 30;
ll constexpr MAX_N = 200001;
void solve() {
    int n, q;
    cin >> n >> q;
    vector g(n + 1, 0);
    for(int i = 1; i <= n; i ++) cin >> g[i];
    vector color(n + 1, 0);
    vector dist_to_cycle(n + 1, -1);
    vector cycle_ids(n + 1, -1);
    vector pos_in_cycle(n + 1, -1);
    vector<int> cycle_len;
    vector up(LOG, vector(n + 1, 0));

    for(int i = 1; i <= n; i ++) up[0][i] = g[i];
    for(int j = 1; j < LOG; j ++) {
        for(int i = 1; i <= n; i ++) {
            int prev = up[j - 1][i];
            up[j][i] = up[j - 1][prev];
        }
    }

    auto get_node = [&] (int start, int step) {
        int ans = start;
        for(int j = 0; j < LOG; j ++) {
            if(step & (1 << j)) {
                ans = up[j][ans];
            }
        }
        return ans;
    };

    for(int i = 1; i <= n; i ++) {
        if(color[i] == 0) {
            vector<int> path;
            auto dfs = [&] (auto& dfs, int u) {
                if(color[u] == 1) {
                    // found cycle
                    int prev_u_idx = -1;
                    for(int idx = 0; idx < path.size(); idx ++) {
                        if(u == path[idx]) {
                            prev_u_idx = idx; 
                            break;
                        }
                    }
                    int cycle_idx = cycle_len.size();
                    int len = path.size() - prev_u_idx;
                    cycle_len.push_back(len);
                    // node on the cycle
                    for(int idx = prev_u_idx; idx < path.size(); idx ++) {
                        int v = path[idx];
                        cycle_ids[v] = cycle_idx;
                        pos_in_cycle[v] = idx - prev_u_idx;
                        dist_to_cycle[v] = 0;
                    }
                    // node outside the cycle
                    for(int idx = prev_u_idx - 1; idx >= 0; idx --) {
                        int v = path[idx];
                        cycle_ids[v] = cycle_idx;
                        pos_in_cycle[v] = -1;
                        dist_to_cycle[v] = prev_u_idx - idx;
                    } 
                    return;
                }
                if(color[u] == 2) {
                    // connect to established chain
                    for(int idx = path.size() - 1; idx >= 0; idx --) {
                        int v = path[idx];
                        cycle_ids[v] = cycle_ids[u];
                        dist_to_cycle[v] = dist_to_cycle[u] + (path.size() - idx);
                        pos_in_cycle[v] = -1;
                    }
                    return;
                }
                color[u] = 1;
                path.push_back(u);
                dfs(dfs, g[u]);
                color[u] = 2;
                path.pop_back();
            };
            dfs(dfs, i);
        }
    }

    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        if(cycle_ids[a] != cycle_ids[b]) {
            cout << -1 << endl;
        } else {
            bool a_on_cycle = pos_in_cycle[a] != -1;
            bool b_on_cycle = pos_in_cycle[b] != -1;
            int cycle_idx = cycle_ids[a];
            int len = cycle_len[cycle_idx];
            if(!a_on_cycle && !b_on_cycle) {
                if(dist_to_cycle[a] < dist_to_cycle[b]) {
                    cout << -1 << endl;
                } else {
                    int after_move = get_node(a, dist_to_cycle[a] - dist_to_cycle[b]);
                    if(after_move == b) {
                        cout << dist_to_cycle[a] - dist_to_cycle[b] << endl;
                    } else {
                        cout << -1 << endl;
                    }
                }
            } else {
                if(!b_on_cycle) {
                    cout << -1 << endl;
                } else if(!a_on_cycle) {
                    int entry = get_node(a, dist_to_cycle[a]);
                    cout << dist_to_cycle[a] +  (pos_in_cycle[b] - pos_in_cycle[entry] + len) % len << endl;
                } else {
                    // both are on the cycle
                    cout << (pos_in_cycle[b] - pos_in_cycle[a] + len) % len << endl;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}