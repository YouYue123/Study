#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct MaxFlow {
    struct Edge {
        int from;
        int to;
        ll cap;
        ll original;
    };

    int n;
    vector<vector<int>> g;
    vector<Edge> edges;
    vector<bool> visit;
    
    MaxFlow(int n): n(n), g(n), visit(n) {}

    void add_edge(int from, int to, int forward, int backward) {
        g[from].push_back(edges.size());
        edges.emplace_back(from, to, forward, forward);
        g[to].push_back(edges.size());
        edges.emplace_back(to, from, backward, backward);
    }

    bool dfs (int u, int sink, ll thres) {
        if(u == sink) return true;
        if(visit[u]) return false;
        visit[u] = true;
        for(auto idx : g[u]) {
            auto& e = edges[idx];
            auto& rev_e = edges[idx ^ 1];
            if(e.cap >= thres && !visit[e.to]) {
                if(dfs(e.to, sink, thres)) {
                    e.cap -= thres;
                    rev_e.cap += thres;
                    return true;
                }
            }
        }
        return false;
    }

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
    
    vector<vector<int>> get_paths(int source, int sink) {
        vector<vector<int>> ans;
        vector<int> path;
        vector used(edges.size(), false);
        auto dfs = [&] (auto& dfs, int u) -> bool {
            if(u == sink) {
                ans.push_back(path);
                return true;
            }
            for(auto idx : g[u]) {
                if(idx % 2 == 1 || used[idx]) continue;
                auto& e = edges[idx];
                ll real_flow = e.original - e.cap;
                if(real_flow == 0) continue;
                used[idx] = true;
                path.push_back(e.to);
                if(dfs(dfs, e.to)) return true;
                path.pop_back();
            }
            return false;
        };
        bool found = false;
        do {
            path.clear();
            path.push_back(source);
            found = dfs(dfs, source);
        } while(found);
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
        mx_flow.add_edge(a, b, 1, 0);
    }
    cout <<  mx_flow.max_flow(0, n - 1) << endl;
    auto paths = mx_flow.get_paths(0, n - 1);
    for(auto& path : paths) {
        cout << path.size() << endl;
        for(auto item : path) cout << item + 1 << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}