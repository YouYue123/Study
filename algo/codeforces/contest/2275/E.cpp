#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector b(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> b[i];
    ll pre = 0, suf = 0;
    auto get_cross_sum = [&] (int i) {
        ll ans = 0;
        ans += a[i] == b[i + 1] ? 2LL : 1LL;
        ans += a[i + 1] == b[i] ? 2LL : 1LL;
        return ans;
    };
    for(int i = 0; i < n - 1; i ++) suf += get_cross_sum(i);
    suf += a[n - 1] == b[n - 1] ? 2LL : 1LL;
    // cout << suf << endl;

    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = max(ans, pre + suf);
        if(i < n - 1) {
            suf -= get_cross_sum(i);
            pre += a[i] == b[i] ? 2LL : 1LL;
            pre += b[i] == a[i + 1] ? 2LL: 1LL;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}