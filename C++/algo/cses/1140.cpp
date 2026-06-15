#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    ll start;
    ll end;
    ll reward;
};
void solve() {
    int n;
    cin >> n;
    vector<Item> items(n);
    ll max_end = 0;
    for(int i = 0; i < n; i ++) {
        cin >> items[i].start >> items[i].end >> items[i].reward;
        max_end = max(max_end, items[i].end);
    }

    sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
        return a.end < b.end;
    });
    vector dp(n, 0LL);
    for(int i = 0; i < n; i ++) {
        dp[i] = i > 0 ? dp[i - 1] : 0;
        dp[i] = max(dp[i], items[i].reward);
        int left = -1, right = i;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(items[mid].end < items[i].start) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if(left != -1) dp[i] = max(dp[i], items[i].reward + dp[left]);
    }
    cout << dp[n - 1] << endl;
    // auto dfs = [&] (this auto&& dfs, int cur_end) -> ll {
    //     // auto it = lower_bound(items.begin(), items.end(), cur_end, [&] (auto& a, int cur_end) {
    //     //     return a.end < cur_end;
    //     // });
    //     ll ans = 0;
    //     for(int i = 0; i < n; i ++) {
    //         if(items[i].start <= cur_end) continue;
    //         ans = max(ans, items[i].reward + dfs(items[i].end));
    //     }
    //     return memo[cur_end] = ans;
    // };
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}