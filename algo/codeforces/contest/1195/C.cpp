#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector h_1(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> h_1[i];
    vector h_2(n, 0LL); 
    for(int i = 0; i < n; i++) cin >> h_2[i];
    vector memo(n, vector(3, -1LL));
    auto dfs = [&] (this auto&& dfs, int i, int prev_row) {
        if(i == n) return 0LL;
        if(memo[i][prev_row] != -1) return memo[i][prev_row];
        ll ans = dfs(i + 1, 0);
        if(prev_row != 1) {
            ans = max(ans, h_1[i] + dfs(i + 1, 1));
        }
        if(prev_row != 2) {
            ans = max(ans, h_2[i] + dfs(i + 1, 2));
        }
        return memo[i][prev_row] = ans;
    };

    cout << dfs(0, 0) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}