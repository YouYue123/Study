#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin  >> a[i];
    unordered_map<ll, ll> cnt;
    for(int i = 0; i < n; i ++) {
        cnt[a[i] % 3] += 1;
    }
    ll ans = cnt[0];
    ans += min(cnt[1], cnt[2]);
    ll cnt_1 = cnt[1], cnt_2 = cnt[2];
    cnt[1] = max(0LL, cnt_1 - cnt_2);
    cnt[2] = max(0LL, cnt_2 - cnt_1);
    ans += cnt[1] / 3;
    ans += cnt[2] / 3;
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