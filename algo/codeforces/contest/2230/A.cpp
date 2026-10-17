#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = min({
        n * a,
        (n / 3) * b + (n % 3) * a,
        (n / 3) * b + (n % 3 / 2) * b + (n % 3 % 2) * a,
        (n / 3) * b + (n % 3 / 2) * b + (n % 3 % 2) * b,
    });

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