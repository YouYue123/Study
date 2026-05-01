#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int x, y;
    cin >> x >> y;
    if(x % 2 == 1 && y % 2 == 1) cout << "NO" << endl;
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