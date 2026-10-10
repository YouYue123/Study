#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    // cout << "sum: " << sum << endl;
    ll ans = INF;
    auto dfs = [&] (auto& dfs, int i, ll mask) -> void {
        if(i == n) {
            ll g1 = 0;
            // cout << "g1 choose: ";
            for(int i = 0; i < n; i ++) {
                if(mask & (1 << i)) {
                    g1 += a[i];
                    // cout << a[i] << " ";
                }
            }
            // cout << endl;
            // cout << "g1 sum: " << g1 << endl;
            ll g2 = sum - g1;
            // cout << "g2 sum: " << g2 << endl;
            ans = min(ans, abs(g2 - g1));
            return;
        }
    
        dfs(dfs, i + 1, mask),
        dfs(dfs, i + 1, mask | (1 << i));
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}