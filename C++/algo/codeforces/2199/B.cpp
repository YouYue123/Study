// Problem: (untitled)
// Contest: 2199 | Index: B
// URL: https://codeforces.com/contest/2199/problem/B
// Rating: N/A | Tags: N/A
// Memory: N/A | Time: N/A
// Author: Yue You

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll common = max(0LL, min(c, d) - max(a, b));
    ll ans = 0;
    ans = common + (c - a - common) + (d - b - common);
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
