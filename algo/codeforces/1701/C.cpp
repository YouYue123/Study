#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << "for: " << n << " " << m << endl;
    vector a(m, 0LL);
    for(int i = 0; i < m; i ++) cin >> a[i];
    vector cnt(n + 1, 0LL);
    for(int i = 0; i < m; i ++) {
        cnt[a[i]] += 1;
    }

    auto is_valid = [&] (ll time) {
        ll finish_cnt = 0;
        for(int worker = 1; worker <= n; worker += 1) {
            ll cur_finish = min(cnt[worker], time);
            cur_finish += max(0LL, time - cnt[worker]) / 2;
            finish_cnt += cur_finish;
        }
        return finish_cnt >= m;
    };
    // cout << "here" << endl;
    ll left = -1, right = 2 * m + 1;
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        if(is_valid(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << left + 1 << endl;

    // sort(cnt.begin(), cnt.end());
    // ll mx = -INF, mn = INF;
    // ll ans = INF;
    // for(int i = 0; i < n; i ++) {
    //     cnt[i];
    // }
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