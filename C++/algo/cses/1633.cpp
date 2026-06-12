#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector dp(n + 1, 0LL);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int d = 1; d <= 6; d ++) {
            if(i - d < 0) break; 
            dp[i] = (dp[i] + dp[i - d]) % MOD;
        }
    }
    cout << dp[n] << endl;
    // auto dfs = [&] (this auto&& dfs, )
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}