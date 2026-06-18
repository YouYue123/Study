#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector visit(n, false);
    vector parent(n, -1);
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visit[0] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == n - 1) {
            int cur_pos = n - 1;
            vector<int> ans;
            while(cur_pos != 0) {
                ans.push_back(cur_pos);
                cur_pos = parent[cur_pos];
            }
            ans.push_back(0);
            
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(auto& item : ans) cout << item + 1 << " ";
            cout << endl;
            return;
        }
        for(auto& nxt : g[cur.first]) {
            if(visit[nxt]) continue;
            visit[nxt] = true;
            parent[nxt] = cur.first;
            q.emplace(nxt, cur.second + 1);
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}