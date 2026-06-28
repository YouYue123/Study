#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Scaling algorithm for computing the maximum flow in a flow network.
// Runs in O(m^2 log C) time.
struct MaxFlow {
    struct Edge {
        ll from;
        ll to;
        ll cap;
    };
    int n;
    vector<vector<int>> g;
    vector<Edge> edges;
    vector<bool> visit;

    MaxFlow(int n): n(n), visit(n), g(n) {};

    void add_edge(ll from, ll to, ll forward, ll backward) {
        g[from].push_back(edges.size());
        edges.emplace_back(from, to, forward);
        g[to].push_back(edges.size());
        edges.emplace_back(to, from, backward);
    };

    bool dfs (int u, int dest, ll thres) {
        if(u == dest) return true;
        if(visit[u]) return false;
        visit[u] = true;
        for(auto idx : g[u]) {
            auto& e = edges[idx];
            auto& rev_e = edges[idx ^ 1];
            if(e.cap >= thres) {
                if(dfs(e.to, dest, thres)) {
                    e.cap -= thres;
                    rev_e.cap += thres;
                    return true;   
                }
            }
        }
        return false;
    };

    ll max_flow(int source, int dest) {
        ll ans = 0;
        for(ll thres = (1LL << 62); thres >= 1; thres /= 2) {
            bool found = false;
            do {
                visit.assign(n, false);
                found = dfs(source, dest, thres);
                ans += thres * found;
            } while(found);
        }
        return ans;
    };
    
    vector<bool> get_reachable(int source) {
        vector<bool> visit(n, false);
        queue<int> q;
        visit[source] = true;
        q.push(source);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int idx : g[u]) {
                auto& e = edges[idx];
                if(e.cap > 0 && !visit[e.to]) {
                    visit[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return visit;
    }

    vector<pair<int, int>> get_min_cut_edges (int source) {
        auto reachable = get_reachable(source);
        vector<pair<int, int>> ans;
        for(auto& e : edges) {
            if(reachable[e.from] && !reachable[e.to]) {
                ans.emplace_back(e.from, e.to);
            }
        }
        return ans;
    }
};