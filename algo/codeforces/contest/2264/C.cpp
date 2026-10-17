#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 998244353;
void solve() {
    ll n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> pre_mul(n + 1, 1LL), suf_mul(n + 1, 1LL);
    for(int i = 0; i < n - 1; i ++) {
        pre_mul[i + 1] = (pre_mul[i] * (n - i - 1)) % MOD;
    }
    for(int i = n - 2; i >= 0; i --) {
        suf_mul[i] = (suf_mul[i + 1] * (n - i - 1)) % MOD;
    }
    vector<ll>  suf_sum(n + 1, 0LL);
    for(int i = n - 1; i >= 0; i --) {
        suf_sum[i] = (suf_sum[i + 1] + a[i]) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        ll w = (pre_mul[i] * suf_mul[i + 1]) % MOD;
        ll contrib = ((suf_sum[i + 1] - ((n - i - 1) * a[i]) % MOD ) + MOD) % MOD;
        ans = (ans + (w * contrib) % MOD) % MOD;
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