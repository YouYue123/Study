// CSES High Score：正权有向图，求 1→n 最长路；若某条 1→n 路径上能无限绕正权环则输出 -1。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
ll constexpr MAX_N = 2501;
struct Edge { ll from, to, score; };

void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<Edge>());
    vector rev_g(n + 1, vector<Edge>());  // 反向边：从 n 沿反向能到的点即「能到 n」
    vector<Edge> edges;
    for(int i = 0; i < m; i ++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(a, b, c);
        rev_g[b].emplace_back(b, a, c);
        edges.emplace_back(a, b, c);
    }

    auto get_reachable = [&] (vector<vector<Edge>>& graph, int start) -> bitset<MAX_N> {
        queue<ll> q;
        q.push(start);
        bitset<MAX_N> visited;
        visited[start] = true;
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
            for(auto& [_, to, __] : graph[u]) {
                if(!visited[to]) {
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
        return visited;
    };
    // 只保留既从 1 可达、又能到达 n 的顶点上的边，避免无关环误判
    auto both_reachable = get_reachable(g, 1) & get_reachable(rev_g, n);
    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;
    // Bellman-Ford 求最长路：n 轮松弛；第 n 轮仍能松弛说明存在可达正环
    for(int i = 1; i <= n; i ++) {
        for(auto& [ from, to, score ] : edges) {
            if(!both_reachable[from] || !both_reachable[to]) continue;
            if(dist[from] != -INF && dist[from] + score > dist[to]) {
                if(i == n) {
                    cout << -1 << endl;
                    return;
                }
                dist[to] = dist[from] + score;
            }
        }
    }
    cout << dist[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}