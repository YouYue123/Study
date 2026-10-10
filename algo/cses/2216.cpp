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
    unordered_set<ll> dict;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        if(!dict.contains(a[i] - 1)) ans += 1;
        dict.insert(a[i]);
    }
    cout << ans << endl;
    // ll cur_min = INF;
    // ll ans = 0;
    // for(int i = 0; i < n; i ++) {
    //     if(cur_min >= a[i]) {
    //         cout << "need take from here: " << a[i] << endl;
    //         ans += 1;
    //     }
    //     cur_min = min(cur_min, a[i]);
    // }
    // cout << ans << endl;
    // vector<ll> g;
    // for(int i = 0; i < n; i ++) {
    //     auto it = upper_bound(g.begin(), g.end(), a[i], greater<ll>());
    //     if(it == g.end()) {
    //         // cout << "push! " << endl;
    //         g.push_back(a[i]);
    //     } else {
    //         // cout << "replace" << endl;
    //         *it = a[i];
    //     }
    // }
    // for(auto item : g) {
    //     cout << item << " ";
    // }
    // cout << endl;
    // cout << g.size() << endl;
    // for(int i = 0; i < n; i ++) {
    //     dict.lower_bound()
    // }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}