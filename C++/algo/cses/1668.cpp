#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1,  vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> colors(n + 1, -1);
    
    auto dfs = [&] (auto& dfs, int cur, int parent, int c) {
        colors[cur] = c;
        // cout << "for: " << cur << endl;
        for(auto nxt : g[cur]) {
            // cout << "nxt: " << nxt << endl;
            if(nxt == parent) continue;
            if(colors[nxt] != -1) {
                if(colors[nxt] == c) return false;
                else continue;
            }
            if(!dfs(dfs, nxt, cur, c ^ 1)) return false;
        }
        return true;
    };
    bool ans = true;
    for(int i = 1; i <= n; i ++) {
        if(colors[i] == -1) {
            // cout << "try for: " << i << endl;
            if(!dfs(dfs, i, 0, 0)) {
                ans = false;
                break;
            }
        }
    }
    if(ans) {
        for(int i = 1; i <= n; i ++) {
            cout << colors[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}