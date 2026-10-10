#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, x;
    cin >> n >> x;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    vector dp(x + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= x; i ++) {
        for(auto& item : a) {
            if(i - item < 0) break;
            dp[i] = min(dp[i], dp[i - item] + 1); 
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}