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
    ll sum = (1 + n) * n / 2;
    if(sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    ll t = sum / 2;
    vector memo(n, vector(t, -1LL));
    auto dfs = [&] (auto& dfs, int i, ll cur_sum) -> ll {
        if(i == n) {
            return cur_sum + n == t ? 1LL : 0LL;
        }
        if(cur_sum >= t) return 0LL;
        if(memo[i][cur_sum] != -1LL) return memo[i][cur_sum];
        return memo[i][cur_sum] = (dfs(dfs, i + 1, cur_sum + i) + dfs(dfs, i + 1, cur_sum) )  % MOD;
    };

    cout << dfs(dfs,1, 0) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}