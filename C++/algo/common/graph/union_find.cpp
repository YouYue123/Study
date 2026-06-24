#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/dsu/
struct UF {
    int n;        
    vector<int> parent;
    vector<int> size; 

    UF(int n): n(n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    int find_root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find_root(parent[x]);
    }

    void unite(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if (root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }

    bool is_connect(int x, int y) {
        return find_root(x) == find_root(y);
    }
};