#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(m * 2 + 1, vector<int>());
    vector rev_g(m * 2 + 1, vector<int>());
    auto get_neg = [&] (int x) {
        if(x > m) return x - m;
        return x + m;
    };

    for(int i = 0; i < n; i ++) {
        char sign_1, sign_2;
        int x_1, x_2;
        cin >> sign_1 >> x_1 >> sign_2 >> x_2;
        if(sign_1 == '-') x_1 = get_neg(x_1);
        if(sign_2 == '-') x_2 = get_neg(x_2);
        g[get_neg(x_1)].push_back(x_2);
        rev_g[x_2].push_back(get_neg(x_1));
        g[get_neg(x_2)].push_back(x_1);
        rev_g[x_1].push_back(get_neg(x_2));
    }

    stack<int> st;
    vector visit_1(2 * m + 1, false);
    auto dfs_1 = [&] (auto& dfs, int u) {
        if(visit_1[u]) return;
        visit_1[u] = true;
        for(auto v : g[u]) dfs(dfs, v);
        st.push(u);
    };
    for(int u = 1; u <= 2 * m; u ++) dfs_1(dfs_1, u);

    vector scc_ids(m * 2 + 1, 0);
    int cur_scc_id = 1;
    auto dfs_2 = [&] (auto& dfs, int u) {
        if(scc_ids[u] != 0) return;
        scc_ids[u] = cur_scc_id;
        for(auto v : rev_g[u]) dfs(dfs, v);
    };
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(scc_ids[u] != 0) continue;
        dfs_2(dfs_2, u);
        cur_scc_id += 1;
    }

    for(int u = 1; u <= m; u++) {
        if(scc_ids[u] == scc_ids[get_neg(u)]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for(int u = 1; u <= m; u ++) {
        cout << (scc_ids[u] < scc_ids[get_neg(u)] ? '-' : '+') << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
