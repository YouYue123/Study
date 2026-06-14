#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    
    vector<pair<int, int>> cur_layer;
    cur_layer.emplace_back(0, 0);
    vector<pair<int, int>> dirs = {
        {1, 0}, {0, 1}
    };
    string ans = "";
    ans += g[0][0];
    vector visit(n, vector(n, false));
    while(!cur_layer.empty()) {
        char best_char = 'Z' + 1;
        for(auto& cur : cur_layer) {
            for(auto& dir : dirs) {
                int n_i = cur.first + dir.first, n_j = cur.second + dir.second;
                if(n_i >= n || n_j >= n) continue;
                best_char = min(best_char, g[n_i][n_j]);
            }
        }
        vector<pair<int, int>> nxt_layer;
        if(best_char <= 'Z') ans += best_char;
        for(auto& cur: cur_layer) {
            for(auto& dir : dirs) {
                int n_i = cur.first + dir.first, n_j = cur.second + dir.second;
                if(n_i >= n || n_j >= n) continue;
                if(visit[n_i][n_j]) continue;
                visit[n_i][n_j] = true;
                if(g[n_i][n_j] == best_char) {
                    nxt_layer.emplace_back(n_i, n_j);
                }
            }
        }
        cur_layer = move(nxt_layer);
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}