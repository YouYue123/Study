#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector a(n, 0LL);
    for(int i = 0; i< n; i ++ ) cin >> a[i];
    vector b(m, 0LL);
    for(int i = 0;i < m; i ++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0, p2 = 0;
    ll ans = 0;
    while(p1 < n && p2 < m) {
        if(abs(a[p1] - b[p2]) <= k) {
            ans += 1;
            p1 += 1;
            p2 += 1;
        } else {
            if(a[p1] < b[p2]) {
                p1 += 1;
            } else {
                p2 += 1;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}