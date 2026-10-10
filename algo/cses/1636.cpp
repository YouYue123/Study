#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector dp(x + 1, 0LL);
    dp[0] = 1;
    for(auto& item : a) {
        for(int i = item; i <= x; i ++) {
            dp[i] = dp[i] + dp[i - item];
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
    }

    cout << dp[x] << endl;
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}