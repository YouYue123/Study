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
    ll cur_max = 0, ans = 0;
    for(int i = 0; i < n; i ++) {
        ll x;
        cin >> x;
        if(x < cur_max) {
            ans += cur_max - x;
        }
        cur_max = max(cur_max, x);
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}