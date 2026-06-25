#include <bits/stdc++.h>
#include "./kosaraju.cpp"
using namespace std;

// SCC 缩点模板（顶点 1..n，分量编号 1..cnt，下标 0 不用）
//
//   vector g(n + 1, vector<int>()), rev_g(n + 1, vector<int>());
//   // ... 建图、读入 node_weight ...
//   auto sc = SccContract::build(n, g, rev_g, node_weight);
//   cout << sc.max_path_weight() << '\n';   // 1686 Coin Collector
//   // sc.comp[u]、sc.dag[c] 用于其它题
struct SccContract {
    int n = 0;
    int cnt = 0;
    vector<int> comp;              // comp[u] = 顶点 u 所属 SCC
    vector<set<int>> dag;          // 缩点后的 DAG（去重边）
    vector<long long> weight;      // 每个 SCC 内的点权之和

    static SccContract build(
        int n,
        const vector<vector<int>>& g,
        const vector<vector<int>>& rev_g,
        const vector<long long>& node_weight = {}
    ) {
        SccContract res;
        res.n = n;
        res.comp = kosaraju(g, rev_g);
        for (int u = 1; u <= n; u++) res.cnt = max(res.cnt, res.comp[u]);

        res.dag.assign(res.cnt + 1, {});
        res.weight.assign(res.cnt + 1, 0);
        for (int u = 1; u <= n; u++) {
            int cu = res.comp[u];
            if ((int)node_weight.size() > u) res.weight[cu] += node_weight[u];
            for (int v : g[u]) {
                if (res.comp[u] != res.comp[v]) res.dag[cu].insert(res.comp[v]);
            }
        }
        return res;
    }

    // 缩点 DAG 上：路径权 = 途经 SCC 的 weight 之和，求最大（与 1686 相同 DP）
    long long max_path_weight() const {
        vector<long long> dist(cnt + 1, 0);
        long long ans = 0;
        for (int u = 1; u <= cnt; u++) {
            dist[u] = max(dist[u], weight[u]);
            ans = max(ans, dist[u]);
            for (int v : dag[u]) dist[v] = max(dist[v], dist[u] + weight[v]);
        }
        return ans;
    }
};
