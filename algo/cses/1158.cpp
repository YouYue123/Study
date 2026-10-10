#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <pair<int, int>> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i].first;
    for(int i = 0; i < n; i ++) cin >> a[i].second;
    
    vector dp(x + 1, 0);
    for(int amt = a[0].first; amt <= x; amt ++) dp[amt] = a[0].second;
    for(int i = 1; i < n; i ++) {
        int price = a[i].first, page = a[i].second;
        for(int amt = x; amt >= 0 ; amt --) {
            if(amt - price >= 0) {
                dp[amt] = max(
                    dp[amt], 
                    dp[amt - price] + page
                );
            }
        }
    }
    cout << dp[x] << endl;
    
    // int memo[1001][100001];
    // memset(memo, -1, sizeof(memo));
    // vector memo(n, vector(x + 1, -1));
    // auto dfs = [&] (auto& dfs, int i, int amt) {
    //     if(i == n) return 0;
    //     if(memo[i][amt] != -1) return memo[i][amt];
    //     int ans = dfs(dfs, i + 1, amt);
    //     if(amt + a[i].first <= x) {
    //         ans = max(ans, a[i].second + dfs(dfs, i + 1, amt + a[i].first));
    //     }
    //     return memo[i][amt] = ans;
    // };

    // cout << dfs(dfs, 0, 0) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}