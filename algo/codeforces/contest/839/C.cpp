#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
double constexpr MIN_DIFF = 1e-6;

struct Item {
    double prob;
    int idx;
    int len;
};
void solve()
{
    int n;
    cin >> n;
    unordered_map<ll, vector<ll>> g;
    for(int i = 0; i < n; i ++) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // auto dfs = [&] (this auto&& dfs, int i, double prob, ll val) {

    // };
    // dfs(0, 1.0, 0);
    queue<Item> q;
    vector visited(n + 1, false);
    q.emplace(1.0, 1, 0);
    visited[1] = true;
    double ans = 0.0;
    ll len = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        vector<int> nxt_list;
        for(auto nxt_idx : g[cur.idx]) {
            if(visited[nxt_idx]) continue;
            visited[nxt_idx] = true;
            nxt_list.push_back(nxt_idx);
        }
        if(nxt_list.size() == 0) {
            ans += cur.prob * cur.len;
        } else {
            double prob = 1.0 / nxt_list.size();
            for(auto nxt_idx : nxt_list) {
                q.emplace(cur.prob * prob, nxt_idx, cur.len + 1);
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}