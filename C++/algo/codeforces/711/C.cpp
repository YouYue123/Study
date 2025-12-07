#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long long INF = 0x3f3f3f3f3f;
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> trees(n);
    for(ll i = 0; i < n; i ++) cin >> trees[i];
    vector costs(n, vector(m, 0LL));
    for(ll i = 0; i < n; i ++) {
        for(ll j = 0; j < m; j ++) {
            cin >> costs[i][j];
        }
    }
    vector memo(
        n,
        vector(
            k + 1,
            vector(
                m + 2,
                -1LL
            )
        )
    );
    auto dfs = [&](this auto&& dfs, int i, int cnt, int prevColor) -> long long {
        if(cnt > k) return INF;
        if(i == n) return cnt == k ? 0 : INF;
        if(memo[i][cnt][prevColor] != -1) return memo[i][cnt][prevColor];
        auto curColor = trees[i];
        long long ans = INF;
        if(curColor != 0) {
            if(curColor == prevColor) {
                ans = dfs(i + 1, cnt, curColor);
            } else {
                ans = dfs(i + 1, cnt + 1, curColor); 
            }
        } else {
            for(ll pColor = 1; pColor <= m; pColor ++) {
                long long remain = INF;
                if(pColor == prevColor) {
                    remain = dfs(i + 1, cnt, pColor);
                } else {
                    remain = dfs(i + 1, cnt + 1, pColor);
                }
                long long cost = costs[i][pColor - 1];
                // cout << " remain: " << remain << " cost: " << cost << endl;
                if(remain != INF) ans = min(ans, remain + cost);
            }
        }
 
        // cout << i << " cnt: " << cnt << " curColor: " << curColor << " prevColor: " <<prevColor << endl;
        return memo[i][cnt][prevColor] = ans;
    };
    long long ans = dfs(0, 0, m + 1);
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}