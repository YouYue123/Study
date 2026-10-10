#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i< n; i++) cin >> a[i];
    ll ans = INF, sum = 0;
    for(int i = 0; i < n; i ++) {
        sum += a[i];
        ll avg = sum / (i + 1);
        ans = min(ans, avg);
        cout << ans << " ";
    }
    cout << endl;
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