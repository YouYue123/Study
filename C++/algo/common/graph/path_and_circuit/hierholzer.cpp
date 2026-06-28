#include <bits/stdc++.h>
using namespace std;

// Hierholzer 欧拉路 / 欧拉回路（无向或有向，边带 id 去重）
//
//   Hierholzer h(n, m);
//   for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; h.add_undirected(a, b, i); }
//   if (auto path = h.euler_circuit(1)) { reverse 已在内部做完; 输出 *path }
struct Hierholzer {
    struct Edge {
        int to;
        int id;
    };

    int n;
    int m;
    vector<vector<Edge>> g;
    vector<int> ptr;
    vector<bool> used;
    vector<int> circuit;

    Hierholzer(int n, int m) : n(n), m(m), g(n + 1), ptr(n + 1), used(m) {}

    void add_undirected(int a, int b, int id) {
        g[a].push_back({b, id});
        g[b].push_back({a, id});
    }

    void add_directed(int a, int b, int id) {
        g[a].push_back({b, id});
    }

    // 从 start 出发；成功则返回顶点序列（长度 m+1），已 reverse 为正向
    optional<vector<int>> euler_circuit(int start = 1) {
        fill(ptr.begin(), ptr.end(), 0);
        fill(used.begin(), used.end(), false);
        circuit.clear();

        auto dfs = [&](this auto&& dfs, int u) -> void {
            while (ptr[u] < (int)g[u].size()) {
                auto [v, eid] = g[u][ptr[u]];
                ptr[u]++;
                if (used[eid]) continue;
                used[eid] = true;
                dfs(v);
            }
            circuit.push_back(u);
        };
        dfs(start);

        if ((int)circuit.size() != m + 1) return nullopt;
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};
