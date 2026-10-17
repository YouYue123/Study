#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> b_pre_sum(n + 1);
    vector<ll> c_pre_sum(n + 1);
    vector<ll> min_pre_sum(n + 1);
    for(int i = 0; i < n; i ++) {
        b_pre_sum[i + 1] = b_pre_sum[i] + a[i] % p;
        c_pre_sum[i + 1] = c_pre_sum[i] + a[i] % q % p;
        min_pre_sum[i + 1] = min_pre_sum[i] + min(a[i] % p , a[i] % q % p);
    }
    ll ans = INF;
    for(int i = k; i <= n; i ++) {
        ll b_val = b_pre_sum[i] - b_pre_sum[i - k];
        ll c_val = c_pre_sum[i] - c_pre_sum[i - k];
        ll left_val =  min_pre_sum[i - k];
        ll right_val = min_pre_sum[n] - min_pre_sum[i];
        ans = min(
            ans,
            min(b_val, c_val) + left_val + right_val
        );
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}