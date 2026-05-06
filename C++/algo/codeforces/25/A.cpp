// Problem: IQ Test
// Contest: 25 | Index: A
// URL: https://codeforces.com/contest/25/problem/A
// Rating: 1300 | Tags: implementation, brute force
// Memory: 256 MB | Time: 2 s
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
    int ans[2] = { -1, -1 };
    for(int i = 0; i < n; i ++) {
        ll a;
        cin >> a;
        if(ans[a % 2] == -1) {
            ans[a % 2] = i + 1;
        } else {
            ans[a % 2] = -2;
        }
    }
    if(ans[0] < 0) cout << ans[1] << endl;
    else cout << ans[0] << endl;
}
