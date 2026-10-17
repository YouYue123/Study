// Problem: Alternating Path
// Contest: 2204 | Index: D
// URL: https://codeforces.com/contest/2204/problem/D
// Rating: 1400 | Tags: constructive algorithms, dfs and similar, graph matchings, graphs, *1400
// Memory: 512 megabytes | Time: 2 seconds
// Author: Yue You
    
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> colors(n, -1);
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        int cnt[2] = {0 , 0 };
        if(colors[i] == -1) {
            bool ok = true;
            auto dfs = [&] (this auto&& dfs, int cur) -> void {
                for(auto& nxt : g[cur]) {
                    if(colors[nxt] == -1) {
                        colors[nxt] = colors[cur] ^ 1;
                        cnt[colors[nxt]] += 1;
                        dfs(nxt);
                    } else if(colors[nxt] == colors[cur]){
                        ok = false;
                    }
                }
            };
            colors[i] = 0;
            cnt[0] = 1;
            dfs(i);
            if(ok) ans += max(cnt[0], cnt[1]);
        }
    }
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
