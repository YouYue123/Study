#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Friend {
    ll m;
    ll s;
};
void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<Friend> f(n);
    for(int i = 0; i < n; i ++) {
        cin >> f[i].m >> f[i].s;
    }
    sort(f.begin(), f.end(), [&] (auto& a, auto& b) {
        return a.m < b.m;
    });
    ll left = 0, right = 0;
    ll cur = 0, ans = 0;
    while(right < n) {
        cur += f[right].s;
        while(f[right].m - f[left].m >= d) {
            cur -= f[left].s;
            left += 1;
        }
        ans = max(ans, cur);
        right += 1;
    }
    cout << ans << endl;
    // auto dfs = [&] (this auto&& dfs, int i, ll low, ll high) -> ll {
    //     if(i == n) return 0LL;
    //     ll ans = dfs(i + 1, low, high);
    //     auto is_within_range = [&] () -> bool {
    //         return abs(f[i].m - low) < d && abs(f[i].m - high) < d;
    //     };
    //     if((low == -1 && high == -1) || is_within_range()) {
    //         ans = max(
    //             ans, 
    //             f[i].s + dfs(i + 1, min(f[i].m, low), max(f[i].m, high))
    //         );
    //     }
    //     return ans;
    // };

    // cout << dfs(0, -1, -1) << endl;
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}