#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll idx; // 1-based idx
    ll val;
};
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    vector<Item> items;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        items.emplace_back(i + 1, a[i]);
    }
    sort(items.begin(), items.end(), [&](auto& a, auto& b) {
        return a.val < b.val;
    });
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(items[i].val * items[j].val > 2 * n) break;
            if(items[i].val * items[j].val == items[i].idx + items[j].idx) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
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