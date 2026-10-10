#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll MOD = 1e9 + 7;
ll MAX_N = 1e6;
void solve() {
    int t;
    cin >> t;
    vector memo(MAX_N + 1, vector(2, -1LL));
    memo[1][0] = 1;
    memo[1][1] = 1;
    for(int i = 2; i <= MAX_N; i ++) {
        memo[i][0] = (4 * memo[i - 1][0] + memo[i - 1][1]) % MOD;
        memo[i][1] = (memo[i - 1][0] + 2 * memo[i - 1][1]) % MOD;
    }

    // auto dfs = [&] (auto& dfs, int i, int state) {
    //     // cout << i << " " << state << endl;
    //     if(i == 1) return 1LL;
    //     if(memo[i][state] != -1) return memo[i][state];
    //     ll ans = 0;
    //     if(state == 0) {
    //         // [=][=]
    //         ans = (4 * dfs(dfs, i - 1, 0) + dfs(dfs, i - 1, 1)) % MOD;
    //     } else {
    //         // [==]
    //         ans = (dfs(dfs, i - 1, 0) + 2 * dfs(dfs, i - 1, 1)) % MOD;
    //     }
    //     return memo[i][state] = ans;
    // };
    for(int i = 0; i < t; i ++) {
        int n;
        cin >> n;
        cout << (memo[n][0] + memo[n][1]) % MOD << endl;
        // cout << (dfs(dfs, n, 0) + dfs(dfs, n, 1)) % MOD << endl;
    }
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}