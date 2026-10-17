#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Coord {
    ll x;
    ll y;
};
void solve()
{
    int n;
    cin >> n;
    vector<Coord> houses(n);
    vector<ll> x_list(n, 0), y_list(n, 0);
    for(int i = 0; i < n; i ++) {
        cin >> houses[i].x >> houses[i].y;
        x_list[i] = houses[i].x;
        y_list[i] = houses[i].y;
    }
    if(n % 2 == 1) {
        cout << 1 << endl;
        return;
    }
    sort(x_list.begin(), x_list.end());
    sort(y_list.begin(), y_list.end());
    // ll nxt = n / 2 + 1 < n ? n / 2 + 1 : n - 1;
    ll x_cnt = x_list[n / 2] - x_list[n / 2 - 1] + 1;
    ll y_cnt = y_list[n / 2] - y_list[n / 2 - 1] + 1;
    cout << x_cnt * y_cnt << endl;
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