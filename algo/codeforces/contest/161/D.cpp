#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    unordered_map<int, vector<int>> g;
    for(int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    auto dfs = [&] (this auto&& dfs, int cur, int parent) -> vector<ll> {
        vector dist(k + 1, 0LL);
        dist[0] = 1;
        for(auto nxt : g[cur]) {
            if(nxt == parent) continue;
            auto nxt_dist = dfs(nxt, cur);
            // cout << "cur: " << cur << " nxt: " << nxt << endl;
            // cout << "nxt_dist: ";
            // for(int i = 0; i < k; i ++) {
            //     cout << nxt_dist[i] << " ";
            // }
            // cout << endl;
            // A node to nxt dist i, means to cur dist i + 1
            // can match a node from prev path with a dist k - (i + 1)
            for(int i = 0; i < k; i ++) ans += dist[k - (i + 1)] * nxt_dist[i];
            for(int i = 0; i < k; i ++) dist[i + 1] += nxt_dist[i];
        }
        return dist;
    };
    dfs(1, -1);
    cout << ans << endl;
}