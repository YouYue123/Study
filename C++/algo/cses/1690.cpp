#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll constexpr MOD = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        g[a].push_back(b);
    }
    int target = (1 << n) - 1;
    vector memo(n, vector(1 << n, -1LL));
    auto dfs = [&] (auto& dfs, int u, int state) {
        if(state == target && u == n - 1) return 1LL;
        if(state == target || u == n - 1) return 0LL;
        if(memo[u][state] != -1) return memo[u][state];
        ll ans = 0;
        for(auto v : g[u]) {
            if(state & (1 << v)) continue;
            ans = (ans + dfs(dfs, v, state | (1 << v))) % MOD;
        }
        return memo[u][state] = ans;
    };

    cout << dfs(dfs, 0, 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}