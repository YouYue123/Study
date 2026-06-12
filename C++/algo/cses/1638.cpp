#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<string> g(n, "");
    for(int i = 0; i < n; i ++) cin >> g[i];
    if(g[0][0] == '*' || g[n - 1][n - 1] == '*') {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> dirs = {
        {1, 0}, {0, 1}
    };
    vector memo(n, vector(n, -1LL));

    auto dfs = [&] (auto& dfs, int i, int j) {
        if(i == n - 1 && j == n - 1) return 1LL;
        if(memo[i][j] != -1) return memo[i][j];
        ll ans = 0;
        for(auto& dir : dirs) {
            int n_i = i + dir.first, n_j = j + dir.second;
            if(n_i == n || n_j == n) continue;
            if(g[n_i][n_j] == '*') continue;
            ans += dfs(dfs, n_i, n_j);
            if(ans >= MOD) ans -= MOD;
        }
        return memo[i][j] = ans;
    };

    cout << dfs(dfs, 0, 0) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}