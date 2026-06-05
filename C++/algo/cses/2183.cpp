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
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    ll cur_max = 1;
    for(ll coin : a) {
        if(coin <= cur_max) {
            cur_max = max(cur_max, cur_max + coin);
        } else {
            cout << cur_max << endl;
            return;
        }
    }
    cout << cur_max << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}