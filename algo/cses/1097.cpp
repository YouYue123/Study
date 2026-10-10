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
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll memo[5001][5001][2];
    memset(memo, -1LL, sizeof(memo));
    auto dfs = [&] (auto& dfs, int left, int right, int state) -> ll {
        if(left > right) return 0LL;        
        if(memo[left][right][state] != -1) return memo[left][right][state];
        return memo[left][right][state] = max(
            a[left] - dfs(dfs, left + 1, right, state ^ 1),
            a[right] - dfs(dfs, left, right - 1, state ^ 1)
        );
    };

    ll max_gap = dfs(dfs, 0, n - 1, 0);
    cout << (sum + max_gap) / 2 << endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}