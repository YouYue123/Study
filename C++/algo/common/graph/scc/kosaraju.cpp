#include <bits/stdc++.h>
using namespace std;

vector<int> kosaraju(
    const vector<vector<int>>& g,
    const vector<vector<int>>& rev_g
) {
    int n = (int)g.size();
    vector<bool> visit(n, false);
    stack<int> st;

    auto dfs1 = [&](this auto&& dfs, int u) -> void {
        visit[u] = true;
        for (int v : g[u]) {
            if (!visit[v]) dfs(v);
        }
        st.push(u);
    };
    for (int i = 0; i < n; i++) {
        if (!visit[i]) dfs1(i);
    }

    vector<int> scc(n, 0);
    int scc_id = 0;
    auto dfs2 = [&](this auto&& dfs, int u) -> void {
        scc[u] = scc_id;
        for (int v : rev_g[u]) {
            if (scc[v] == 0) dfs(v);
        }
    };
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (scc[u] == 0) {
            ++scc_id;
            dfs2(u);
        }
    }
    return scc;
}