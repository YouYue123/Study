#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll t;
    cin >> t;
    for(int i = 0; i < t; i ++) {
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        ll base = 0;
        ll offset = 0;
        if(x >= y) {
            offset = y - 1;
            if(x % 2 == 0) {
                base = x * x;
                offset = -offset;
            } else {
                base = (x - 1) * (x - 1) + 1;
            }
        } else {
            offset = x - 1;
            if(y % 2 == 1) {
                base = y * y;
                offset = -offset;
            } else {
                base = (y - 1) * (y - 1) + 1;
            }
        }
        ans = base + offset;
        cout << ans << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}