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
    ll cur_sum = 0, ans = -INF, min_sum = 0;
    for(int i = 0; i < n; i ++) {
        cur_sum += a[i];
        ans = max(ans, cur_sum - min_sum);
        min_sum = min(min_sum, cur_sum);
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}