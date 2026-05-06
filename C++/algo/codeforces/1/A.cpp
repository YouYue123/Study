// Problem: Theatre Square
// Contest: 1 | Index: A
// URL: https://codeforces.com/contest/1/problem/A
// Rating: N/A | Tags: N/A
// Memory: N/A | Time: N/A
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
    ull n, m, a;
    cin >> n >> m >> a;
    ull h = (n % a == 0 ? n / a : n / a + 1);
    ull v = (m % a == 0 ? m / a : m / a + 1);
    ull ans = h * v;
    cout  << ans << endl;
}
