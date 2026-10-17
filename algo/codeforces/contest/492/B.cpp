// Problem: Vanya and Lanterns
// Contest: 492 | Index: B
// URL: https://codeforces.com/contest/492/problem/B
// Rating: 1200 | Tags: implementation, math, sortings
// Memory: 256 MB | Time: 1 s
// Author: Yue You

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, l;
    cin >> n >> l;
    vector<double> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    double ans = max( a[0], (l - a[n - 1]));
    for(int i = 0; i < n - 1; i ++) {
        ans = max(ans, (a[i + 1] - a[i]) / 2.0);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
