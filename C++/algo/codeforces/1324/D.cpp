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
    vector b(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> b[i];
    vector a_b(n, 0LL);
    for(int i = 0; i < n; i ++) a_b[i] = a[i] - b[i];
    sort(a_b.begin(), a_b.end());
    ll ans = 0, cnt = 1;
    for(int i = 0; i < n; i ++) {
        if(a_b[i] <= 0) continue;
        auto it = upper_bound(a_b.begin(), a_b.end(), -a_b[i]);
        if(it != a_b.end()) ans += a_b.end() - it - cnt;
        cnt += 1;
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}