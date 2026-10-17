#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    ll ans = 0;
    ans += d / k + d / l + d / m + d / n;
    // // cout << ans << endl;
    ans -= d / lcm(k, l) + d / lcm(k, m) + d / lcm(k, n) + d / lcm(l, m) + d / lcm(l, n) + d / lcm(m, n);
    // // cout << ans << endl;
    ans += d / lcm(k, lcm(l, m)) + d / lcm(k, lcm(l, n)) + d / lcm(k, lcm(m, n)) + d / lcm(l, lcm(m , n));
    // // cout << ans << endl;
    ans -= d / lcm(lcm(k, l), lcm(m, n));
    cout << ans << endl;
}