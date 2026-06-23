#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Edge { ll a, b, c; };
struct UF {
    int cnt;
    vector<int> parent;
    vector<int> size;
    UF(int n): cnt(n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }

    void unite(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        cnt -= 1;
        if(size[root_x] >= size[root_y]) {
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

    bool is_connected(int x, int y) {
        return find_root(x) == find_root(y);
    }
};
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(ll i = 0; i < m; i ++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;  
    }
    sort(edges.begin(), edges.end(), [&] (auto& a, auto& b) {
        return a.c < b.c;
    });
    auto uf = UF(n);
    ll ans = 0;
    for(auto [a, b, c] : edges) {
        // cout << "a: " << a << " b: " << b << " c: " << c << endl;
        a -= 1;
        b -= 1;
        if(uf.is_connected(a, b)) continue;
        uf.unite(a, b);
        ans += c;
    }
    if(uf.cnt == 1) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}