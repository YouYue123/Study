#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll b = y / x;
    // cout << b << endl;
    if(b <= 2) cout << "NO" << endl;
    else cout << "YES" << endl;
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