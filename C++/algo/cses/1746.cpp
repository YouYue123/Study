#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector memo(n, vector(m + 1, -1LL));
    
    auto dfs = [&] (auto& dfs, int i, int prev) -> ll {
        if(i == n) return 1LL;
        if(memo[i][prev] != -1) return memo[i][prev];
        ll ans = 0;
        if(a[i] != 0) {
            if(abs(a[i] - prev) <= 1) ans = dfs(dfs, i + 1, a[i]);
        } else {
            for(int cur = max(1, prev - 1); cur <= min(m, prev + 1); cur ++) {
                ans = (ans + dfs(dfs, i + 1, cur)) % MOD;
            }
        }
        return memo[i][prev] = ans;
    };

    ll ans = 0;
    if(a[0] == 0) {
        for(int cur = 1; cur <= m; cur ++) {
            ans = (ans + dfs(dfs, 1, cur)) % MOD;
        }
    } else {
        ans = dfs(dfs, 1, a[0]);
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}