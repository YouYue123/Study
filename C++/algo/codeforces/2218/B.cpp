#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n = 7;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        if(i == n - 1) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
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