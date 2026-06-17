#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct UF {
    vector<int> parent;
    vector<int> size;
    UF(int N) {
        parent.resize(N);
        size.assign(N, 1);
        for(int i = 0; i < N; i ++) parent[i] = i;
    }
    void unite(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        if(size[root_x] > size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }

    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }
    
    bool is_connect(int x, int y) {
        return find_root(x) == find_root(y);
    }

};
void solve() {
    int n, m;
    cin >> n >> m;
    auto uf = UF(n);
    vector g(n, vector<int>());
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.unite(a, b);
    }
    vector<pair<int, int>> ans;
    for(int i = 1; i < n; i ++) {
        if(!uf.is_connect(i, i - 1)) {
            ans.emplace_back(i - 1, i);
            uf.unite(i, i - 1);
        }
    }
    cout << ans.size() << endl;
    for(auto& item : ans) {
        cout << item.first + 1 << " " << item.second + 1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}