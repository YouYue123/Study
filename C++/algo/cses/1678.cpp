#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector g(n + 1, vector<ll>());
    for(int i = 0; i < m; i ++) {
        ll a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    vector nxt_arr(n + 1, 0);
    vector color(n + 1, 0);
    ll cycle_start = -1;
    auto dfs = [&] (auto & dfs, int cur, int parent) {
        color[cur] = 1;
        for(auto nxt : g[cur]) {
            if(color[nxt] == 1) {
                nxt_arr[cur] = nxt;
                cycle_start = nxt;
                return true;
            }
            if(color[nxt] == 2) continue;
            nxt_arr[cur] = nxt;
            if(dfs(dfs, nxt, cur)) return true;
            nxt_arr[cur] = 0;
        }
        color[cur] = 2;
        return false;
    };

    for(int i = 1; i <= n; i ++) {
        if(color[i] == 2) continue;
        if(dfs(dfs, i, -1)) {
            ll cur = cycle_start;
            vector<int> ans;
            do {
                ans.push_back(cur);
                cur = nxt_arr[cur];
            } while(cur != cycle_start);
            ans.push_back(cycle_start);
            cout << ans.size() << endl;
            for(ll item : ans) cout << item << " ";
            cout << endl;
            return;
        }
        color[i] = 2;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}