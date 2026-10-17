#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if(n == 2 || n == 3) {
        cout << 1 << endl;
    } else {
        ll dist_1 = min(x1, x2) + (n - max(x1, x2));
        ll dist_2 = abs(x1 - x2);
        cout << min(dist_1, dist_2) + k << endl;
    }
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