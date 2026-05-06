#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    // cout << n << endl;
    // cout << gcd(n, a) << " " << gcd(m, b) << endl;
    bool ans = gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(n, m) <= 2;
    // cout << n % a  << " " << m % b << endl;
    cout << (ans ? "YES" : "NO") << endl;
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

// 1 1 YES
// 1 1 YES
// 2 1 NO 
// 6 1 NO
// 1 1 YES
// 1 1 NO
// 2 1 NO
// 1 2 NO
// 1 1 YES
// 1000000000 1000000000 NO