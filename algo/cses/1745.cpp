#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    set<ll> ans;

    for(int i = 0; i < n; i ++) {
        auto cur = ans;
        for(auto& item : ans) {
            cur.insert(item + a[i]);
        }
        cur.insert(a[i]);
        ans = move(cur);
    }
    // auto dfs = [&] (this auto&& dfs, int i, ll sum) {
    //     if(i == n) {
    //         if(sum != 0) ans.insert(sum);
    //         return;
    //     }
    //     dfs(i + 1, sum);
    //     dfs(i + 1, sum + a[i]);
    // };
    // dfs(0, 0);
    cout << ans.size() << endl;
    for(auto& item : ans) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}