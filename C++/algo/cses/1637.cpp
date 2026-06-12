#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;

    auto get_digits = [&] (int x) {
        set<int> digits;
        while(x > 0) {
            digits.insert(x % 10);
            x /= 10;
        }
        return digits;
    };
    vector dp(n + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        auto digits = get_digits(i);
        for(int d : digits) {
            if(i - d < 0) break;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}