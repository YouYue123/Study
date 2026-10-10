#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i];
    vector<pair<int, int>> dirs = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector visit(n, vector(m, false));

    auto dfs = [&] (auto& dfs, int i, int j) -> void {
        for(auto& dir : dirs) {
            int n_i = i + dir.first, n_j = j + dir.second;
            if(n_i >= n || n_i < 0 || n_j >= m || n_j < 0) continue;
            if(visit[n_i][n_j] || g[n_i][n_j] == '#') continue;
            visit[n_i][n_j] = true;
            dfs(dfs, n_i, n_j);
        }
    };
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(g[i][j] == '#' || visit[i][j]) continue;
            ans += 1;
            dfs(dfs, i, j);
        }
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}