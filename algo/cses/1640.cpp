#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int idx;
    int val;
};
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<Item> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].val;
        a[i].idx = i + 1;
    }
    sort(a.begin(), a.end(), [&] (auto& a, auto& b) {
        return a.val < b.val;
    });
    int left = 0, right = n - 1;
    while(left < right) {
        if(a[left].val + a[right].val == x) {
            cout << a[left].idx << " " << a[right].idx << endl;
            return;
        } else if(a[left].val + a[right].val < x) {
            left += 1;
        } else {
            right -= 1;
        }
    }
    // for(int i = 0; i < n; i ++) {
    //     ll t = x - a[i].val;
    //     auto it = lower_bound(a.begin() + i + 1, a.end(), t, [&] (auto& a, int val) {
    //         return a.val < val;
    //     });
    //     if(it != a.end()) {
    //         if(a[i].val + it->val == x) {
    //             cout << a[i].idx << " " << it->idx << endl;
    //             return;
    //         }
    //     }
    // }
    // unordered_map<int, int> dict;
    // for(int i = 0; i < n; i ++) {
    //     ll t = x - a[i];
    //     if(dict.contains(t)) {
    //         cout << dict[t] + 1 << " " << i + 1 << endl;
    //         return;
    //     }
    //     dict[a[i]] = i;
    // }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}