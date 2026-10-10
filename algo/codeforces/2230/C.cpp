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
    vector<ll> c(n, 0);
    for(int i = 0; i < n; i ++) cin >> c[i];
    ll cnt_1 = 0, cnt_more_than_2 = 0;
    ll ans = 0, supp = 0;
    for(int i = 0; i < n; i ++) {
        if(c[i] == 1) {
            cnt_1 += 1;
        } else {
            supp += c[i] / 2 - 1;
            ans += c[i];
            if(c[i] > 0) cnt_more_than_2 += 1;
        }
    }
    if(cnt_more_than_2 == 1) supp += 1;
    ans += min(cnt_1, max(0LL, supp));
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