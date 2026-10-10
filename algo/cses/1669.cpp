#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct UF {

};
void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> parent(n + 1, 0), visit(n + 1, false);
    int start = -1, end = -1;
    auto dfs = [&] (auto& dfs, int u, int p) {
        visit[u] = true;
        parent[u] = p; 
        for(int v : g[u]) {
            if(v == p) continue;;
            if(visit[v]) {
                start = u, end = v;
                return true;
            }
            if(dfs(dfs, v, u)) return true;
        }
        return false;
    };
    for(int i = 1; i <= n; i ++) {
        if(!visit[i]) {
            if(dfs(dfs, i, 0)) break;
        }
    }
    if(start == -1) {
        cout << "IMPOSSIBLE" << endl;        
    } else {
        vector<int> ans;
        int cur = start;
        while(cur != end) {
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(end);
        ans.push_back(start);
        cout << ans.size() << endl;
        for(int item : ans) cout << item << " ";
        cout << endl; 
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}