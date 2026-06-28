#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
// Dinic's algorithm for computing the maximum flow in a flow network.
// Runs in O(m n^2) time.
struct MaxFlow {
    struct Edge {
        int from;
        int to;
        ll w;
    };

    int n, source, sink;
    vector<vector<int>> g;
    vector<Edge> edges;
    vector<int> level;
    vector<int> ptr;
    ll flow = 0;

    MaxFlow(int n, int source, int sink)
        : n(n), source(source), sink(sink), g(n), level(n), ptr(n) {}

    void add_edge(int from, int to, ll forward, ll backward) {
        g[from].emplace_back(edges.size());
        edges.emplace_back(from, to, forward);
        g[to].emplace_back(edges.size());
        edges.emplace_back(to, from, backward);
    }

    bool bfs() {
        level.assign(n, -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            for (int i : g[s]) {
                auto &e = edges[i];
                if (level[e.to] == -1 && e.w > 0) {
                    level[e.to] = level[s] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }

    ll dfs(int node, ll flow) {
        if (node == sink) return flow;
        for (int &it = ptr[node]; it < g[node].size(); ++it) {
            int i = g[node][it];
            auto &forward_e = edges[i];
            auto &reverse_e = edges[i ^ 1];
            if (forward_e.w > 0 && level[forward_e.to] == level[node] + 1) {
                ll f = dfs(forward_e.to, min(flow, forward_e.w));
                if (f > 0) {
                    forward_e.w -= f;
                    reverse_e.w += f;
                    return f;
                }
            }
        }
        return 0;
    }

    ll max_flow() {
        while (bfs()) {
            ptr.assign(n, 0);
            ll f;
            while ((f = dfs(source, INF)) > 0) flow += f;
        }
        return flow;
    }
};