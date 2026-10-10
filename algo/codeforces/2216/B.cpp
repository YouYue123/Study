#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int constexpr INF = 0x3f3f3f3f;

void solve()
{
    ll ct, ch, cu;
    cin >> ct >> ch >> cu;
    ll ans = 0LL;
    ans += (ct + ch + cu) * 3LL;
    // cout << "origin: " << ans << endl;
   
    ans -= 2 * min(cu, ct);
    ct -= min(cu, ct);
    // cout << "after U: " << ans << endl;

    ans -= min(2 * ch, ct);
    ct -= min(2 * ch, ct);
    // cout << "after H: " << ans << endl;

    ans -= max(0LL, ct - 1);
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