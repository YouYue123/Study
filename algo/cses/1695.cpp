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
void solve() {
    int n, m;
    cin >> n >> m;
    auto mx_flow = MaxFlow(n);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        mx_flow.add_edge(a, b, 1, 1);
    }
    cout << mx_flow.max_flow(0, n - 1) << endl;
    auto ans = mx_flow.get_min_cut_edges(0);
    for(auto item : ans) cout << item.first + 1 << " " << item.second + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}