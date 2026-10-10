#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    unordered_map<int, vector<int>> g;
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    auto dfs = [&] (this auto&& dfs, int cur, int parent, int cnt) -> void {
        // cout << "cur: " << cur << "cnt: " << cnt << endl;

        if(cnt > m) return; 
        if(g[cur].size() == 1 && cur != 1) {
            ans += 1;
            return;
        }
        // cout <<  g[cur].size() << endl;
        for(int nxt : g[cur]) {
            if(nxt == parent) continue;
            int nxt_cnt = a[nxt - 1] == 0 ? 0 : cnt + 1;
            dfs(nxt, cur, nxt_cnt);
        }
    };
    dfs(1, -1, a[0] == 1 ? 1 : 0);
    cout << ans << endl;
}