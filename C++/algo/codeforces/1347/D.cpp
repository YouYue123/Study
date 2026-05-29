#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector a(n, 0LL);
    for(int i = 0 ; i < n; i ++) cin >> a[i];
    vector<ll> mod_a;
    for(int i = 0; i < n; i ++) {
        if(a[i] % k != 0) mod_a.push_back(a[i] % k);
    }
    sort(mod_a.begin(), mod_a.end());
    int prev = -1, cnt = 0;
    ll ans = 0;
    for(int i = 0; i < mod_a.size(); i ++) {
        // cout << mod_a[i] << " ";
        if(prev != mod_a[i]) {
            cnt = 1;
        } else {
            cnt += 1;
        }
        // cout << k * cnt - mod_a[i] << " ";
        ans = max(ans, k * cnt - mod_a[i] + 1);
        prev = mod_a[i];
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