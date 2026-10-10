#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;


void solve() {
    int memo[501][501];
    memset(memo, -1, sizeof(memo));
    int a, b;
    cin >> a >> b;
    auto dfs = [&] (auto& dfs, int i, int j) -> ll {
        if(i == j) return 0LL;
        if(i == 0 || j == 0) return INF;
        if(memo[i][j] != -1) return memo[i][j];
        ll ans = INF;
        for(int len = 1; len < i; len ++) {
            ans = min(
                ans,
                1LL + dfs(dfs, len, j) + dfs(dfs, i - len, j)
            );
        }
        for(int len = 1; len < j; len ++) {
            ans = min(
                ans,
                1LL + dfs(dfs, i, len) + dfs(dfs, i, j - len)
            );
        }
        return memo[i][j] = ans;
    };

    cout << dfs(dfs, a, b) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}