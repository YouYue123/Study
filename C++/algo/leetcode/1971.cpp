#include <bits/stdc++.h>
using namespace std;

// 1971. Find if Path Exists in Graph [E]
// LeetCode find-if-path-exists-in-graph

class UF {
private:
    vector<int> parent;
    vector<int> size;
    int find(int x) {
        if(parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }
public:
    UF (int n) {
        size.assign(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(size[root_x] >= size[root_y]) {
            size[root_x] += size[root_y];
            parent[root_y] = root_x;
        } else {
            size[root_y] += size[root_x];
            parent[root_x] = root_y;
        }
    }
    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UF uf(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            uf.unite(u, v);
        }
        return uf.is_connected(source, destination);
    }
};