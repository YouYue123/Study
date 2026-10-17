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
    ll sum = 0;
    vector h(n, 0LL);
    vector presum(n + 1, 0LL);
    for(int i = 0; i < n; i ++) cin >> h[i];
    for(int i = 0; i < n; i ++) {
        presum[i + 1] = presum[i] + h[i];
    }
    bool ok = true;
    for(int i = 0; i < n; i ++) {
        ll t = i * (i + 1) / 2;
        if(presum[i + 1] < t) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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