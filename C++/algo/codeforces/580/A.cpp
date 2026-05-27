#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    ll prev = -INF;
    ll cur = 0;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] >= prev) {
            cur += 1;
        } else {
            cur = 1;
        }
        prev = a[i];
        ans = max(ans, cur);
    }
    cout << ans  << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}