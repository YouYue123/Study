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
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector memo(n, vector(2, vector(2, -1LL)));
    auto dfs = [&] (this auto&& dfs, int i, bool is_prev_sport, bool is_prev_contest) -> ll {
        if(i == n) return 0LL;
        if(memo[i][is_prev_sport][is_prev_contest] != -1) return memo[i][is_prev_sport][is_prev_contest];
        ll ans = 1 + dfs(i + 1, false, false);
        if(a[i] == 1) {
            if(!is_prev_contest) ans = min(ans, dfs(i + 1, false, true));
        } else if(a[i] == 2) {
            if(!is_prev_sport) ans = min(ans, dfs(i + 1, true, false));
        } else if(a[i] == 3) {
            if(!is_prev_sport) ans = min(ans, dfs(i + 1, true, false));
            if(!is_prev_contest) ans = min(ans, dfs(i + 1, false, true));
        }
        return memo[i][is_prev_sport][is_prev_contest] = ans;
    };

    cout << dfs(0, false, false) << endl;;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}