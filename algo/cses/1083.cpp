#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector a(n, 0LL);
    ll sum = 0;
    for(int i = 0; i < n - 1; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << n * (n + 1) / 2 - sum << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}