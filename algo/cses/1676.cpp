#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct UF {
    int cnt;
    int max_size;
    vector<int> parent;
    vector<int> size;
    UF(int n) : cnt(n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
        max_size = 1;
    };
    void unite(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x == root_y) return;
        cnt -= 1;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            max_size = max(max_size, size[root_x]);
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            max_size = max(max_size, size[root_y]);
            parent[root_x] = root_y;
        }
    }
    int find_root(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    auto uf = UF(n);
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        uf.unite(a, b);
        cout << uf.cnt << " " << uf.max_size << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}