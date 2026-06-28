#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

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

    void add_edge(ll from, ll to, ll w) {
        g[from].push_back(edges.size());
        edges.emplace_back(from, to, w);
        g[to].push_back(edges.size());
        edges.emplace_back(to, from, 0);
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
};

int main() {
    int n, m;
    cin >> n >> m;
    auto mx_flow = MaxFlow(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        mx_flow.add_edge(a, b, w);
    }
    cout << mx_flow.max_flow(0, n - 1) << endl;
}