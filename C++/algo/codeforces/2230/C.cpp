#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector c(n, 0LL);
    ll cnt_ge_2 = 0, cnt_eq_1 = 0;
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
        if(c[i] >= 2) cnt_ge_2 += 1;
        else if(c[i] == 1) cnt_eq_1 += 1;
    }

    ll ans = 0;
    if(cnt_ge_2 == 1) {
        ans = c.back() + min(c.back() / 2, cnt_eq_1);
    } else if(cnt_ge_2 >= 2) {
        ll sum_val = 0, cap = 0;
        for(int i = 0; i < n; i ++) {
            if(c[i] >= 2) {
                sum_val += c[i];
                cap += (c[i] - 2) / 2;
            }
        }
        ans = sum_val + min(cap, cnt_eq_1);
    }
    if(ans < 3) ans = 0;
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

