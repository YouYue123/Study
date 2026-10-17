#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n, t;
    cin >> n >> t;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector presum(n + 1, 0LL);
    for(int i = 0; i < n ; i ++) presum[i + 1] = presum[i] + a[i];
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        ll left = i - 1, right = n;
        auto is_valid = [&] (int x) -> bool {
            return presum[x + 1] - presum[i] > t;
        };
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(is_valid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        // cout << is_valid
        if(left >= i) {
            ans = max(ans, left - i + 1);
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