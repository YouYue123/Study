#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector rev_g(n + 1, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }
    stack<int> st;
    vector visit(n + 1, false);
    auto dfs = [&] (auto& dfs, int i) {
        if(visit[i]) return;
        visit[i] = true;
        for(auto& nxt : g[i]) dfs(dfs, nxt);
        st.push(i);
    };
    for(int i = 1; i <= n; i ++) {
        if(!visit[i]) dfs(dfs, i);
    }
    visit.assign(n + 1, false);
    vector scc(n + 1, 0);
    int scc_id = 1;
    auto dfs_on_rev = [&] (auto& dfs, int i) {
        if(visit[i]) return;
        visit[i] = true;
        for(auto& nxt : rev_g[i]) dfs(dfs, nxt);
        scc[i] = scc_id;
    };

    while(!st.empty()) {
        auto cur = st.top();
        st.pop();
        if(!visit[cur]) {
            dfs_on_rev(dfs_on_rev, cur);
            scc_id += 1;
        }
    }

    auto can_reach = [&] (int start, int target) {
        vector<bool> visited(n + 1, false);
        auto dfs = [&] (auto&& dfs, int u) -> bool {
            if(u == target) return true;
            visited[u] = true;
            for(int v : g[u]) {
                if(visited[v]) continue;
                if(dfs(dfs, v)) return true;
            }
            return false;
        };
        return dfs(dfs, start);
    };
    int scc_1 = scc[1];
    for(int i = 2; i <= n; i ++) {
        // cout << "i: " << i << " scc_id: " << scc[i] << endl;
        if(scc[i] != scc_1) {
            cout << "NO" << endl;
            bool can_1_reach_i = can_reach(1, i);
            if(can_1_reach_i) {
                cout << i << " " << 1 << endl;
            } else {
                cout << 1 << " " << i << endl;
            }
            return;
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}