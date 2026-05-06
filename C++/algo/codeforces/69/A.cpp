// Problem: Young Physicist
// Contest: 69 | Index: A
// URL: https://codeforces.com/contest/69/problem/A
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
    ll n;
    cin >> n;
    ll x = 0, y = 0, z = 0;
    for(int i = 0; i < n; i ++) {
        ll c_x, c_y, c_z;
        cin >> c_x >> c_y >> c_z;
        x += c_x; 
        y += c_y;
        z += c_z;
    }
    string ans = "";
    if(x == 0 && y == 0 == z == 0) ans = "YES";
    else ans = "NO";
    cout << ans << endl;
}
