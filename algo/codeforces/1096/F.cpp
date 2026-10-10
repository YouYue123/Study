#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1), cnt(n + 1);
    for(ll i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    vector<ll> have(n + 1);
    have[n] = cnt[n];
    for(ll i = n - 1; i >= 1; i--) have[i] = have[i + 1] + cnt[i];

    ll init = 0, aft = 0;
    for(ll i = 1; i <= n; i++) {
        init += i * v[i];
        aft += have[i] * (2 * n - have[i] + 1) / 2;
    }

    ll cur = aft - init, mx = 0;
    for(ll i = 1; i <= n; i++) mx = max(mx, i - n + have[v[i]] - 1);

    cout << cur + mx << endl;
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