#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Scaling Ford–Fulkerson: O(m^2 log C). Adjacency stores edge indices; i^1 is the reverse arc.
struct MaxFlow {
    struct Edge {
        ll from, to;
        ll cap;       // residual capacity
        ll original;  // initial forward cap (for flow decomposition)
    };
    int n;
    vector<vector<int>> g;
    vector<Edge> edges;
    vector<bool> visit;

    MaxFlow(int n): n(n), visit(n), g(n) {}

    // add_edge adds forward [from→to] then reverse [to→from] as a pair (2i, 2i+1)
    void add_edge(ll from, ll to, ll forward, ll backward) {
        g[from].push_back(edges.size());
        edges.emplace_back(from, to, forward, forward);
        g[to].push_back(edges.size());
        edges.emplace_back(to, from, backward, backward);
    }

    // push one augmenting path with flow >= thres (greedy, one path per call)
    bool dfs(int u, int dest, ll thres) {
        if (u == dest) return true;
        if (visit[u]) return false;
        visit[u] = true;
        for (int idx : g[u]) {
            auto& e = edges[idx];
            auto& rev_e = edges[idx ^ 1];
            if (e.cap >= thres && dfs(e.to, dest, thres)) {
                e.cap -= thres;
                rev_e.cap += thres;
                return true;
            }
        }
        return false;
    }

    // scale threshold from high bit down to 1
    ll max_flow(int source, int dest) {
        ll ans = 0;
        for (ll thres = 1LL << 62; thres >= 1; thres /= 2) {
            bool found;
            do {
                visit.assign(n, false);
                found = dfs(source, dest, thres);
                ans += thres * found;
            } while (found);
        }
        return ans;
    }

    // vertices reachable from source in the residual graph (cap > 0)
    vector<bool> get_reachable(int source) {
        vector<bool> vis(n, false);
        queue<int> q;
        vis[source] = true;
        q.push(source);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int idx : g[u]) {
                auto& e = edges[idx];
                if (e.cap > 0 && !vis[e.to]) {
                    vis[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return vis;
    }

    // s-side → t-side saturated forward edges in a minimum cut
    vector<pair<int, int>> get_min_cut_edges(int source) {
        auto reachable = get_reachable(source);
        vector<pair<int, int>> ans;
        for (auto& e : edges) {
            if (reachable[e.from] && !reachable[e.to])
                ans.emplace_back(e.from, e.to);
        }
        return ans;
    }

    // decompose max flow into s→t paths (unit-capacity style; e.g. assignment output)
    vector<vector<int>> get_paths(int source, int sink) {
        vector<vector<int>> ans;
        vector<int> path;
        vector used(edges.size(), false);
        auto dfs = [&](auto& dfs, int u) -> bool {
            if (u == sink) {
                ans.push_back(path);
                return true;
            }
            for (int idx : g[u]) {
                if (idx % 2 == 1 || used[idx]) continue;  // forward edges only
                auto& e = edges[idx];
                ll flow = e.original - e.cap;
                if (flow == 0) continue;
                used[idx] = true;
                path.push_back(e.to);
                if (dfs(dfs, e.to)) return true;
                path.pop_back();
            }
            return false;
        };
        bool found;
        do {
            path = {source};
            found = dfs(dfs, source);
        } while (found);
        return ans;
    }
};
