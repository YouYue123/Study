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

    MaxFlow(int n): n(n), g(n), visit(n) {}

    void add_edge(int from, int to, int forward, int backward) {
        g[from].push_back(edges.size());
        edges.emplace_back(from, to, forward);
        g[to].push_back(edges.size());
        edges.emplace_back(to, from, backward);
    }
    bool dfs (int u, int sink, ll thres) {
        if(u == sink) return true;
        if(visit[u]) return false;
        visit[u] = true;
        for(auto idx : g[u]) {
            auto& e = edges[idx];
            auto& rev_g = edges[idx ^ 1];
            if(e.cap >= thres && !visit[e.to]) {
                if(dfs(e.to, sink, thres)) {
                    e.cap -= thres;
                    rev_g.cap += thres;
                    return true;
                }
            }
        }
        return false;
    };
    
    ll max_flow(int source, int sink) {
        ll ans = 0;
        for(ll thres = (1LL << 62); thres >= 1; thres /= 2) {
            bool found = false;
            do {
                visit.assign(n, false);
                found = dfs(source, sink, thres);
                ans += thres * found;
            } while(found);
        }
        return ans;
    }

    vector<bool> get_reachable (int source) {
        vector visit(n, false);
        visit[source] = true;
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto idx : g[u]) {
                auto& e = edges[idx];
                if(e.cap > 0 && !visit[e.to]) {
                    visit[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return visit;
    }

    vector<pair<int, int>> get_min_cut_edges(int source) {
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
    ll n, m, k;
    cin >> n >> m >> k;
    auto mx_flow = MaxFlow(m + n + 2);
    int source = 0, sink = m + n + 1;
    vector<bool> boy_linked(n + 1, false);
    vector<bool> girl_linked(n + m + 1, false);
    for(int i = 0; i < k; i ++) {
        ll a, b;
        cin >> a >> b;
        b += n;
        if(!boy_linked[a]) {
            boy_linked[a] = true;
            mx_flow.add_edge(source, a, 1, 0);
        }
        mx_flow.add_edge(a, b, 1, 0);
        if(!girl_linked[b]) {
            girl_linked[b] = true;
            mx_flow.add_edge(b, sink, 1, 0);
        }
    }
    cout << mx_flow.max_flow(source, sink) << endl;
    for(int i = 0; i < mx_flow.edges.size(); i += 2) {
        auto& e = mx_flow.edges[i];
        if(e.from != source && e.to != sink && e.cap == 0) {
            cout << e.from << " " << (e.to - n) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}