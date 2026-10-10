#include <bits/stdc++.h>
using namespace std;

// 1319. Number of Operations to Make Network Connected [M]
// LeetCode number-of-operations-to-make-network-connected

struct UF {
    vector<int> parent;
    vector<int> size;
    int cnt;
    UF(int n) {
        cnt = n;
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        size.assign(n, 1);
    }
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return;
        if(size[rootY] > size[rootX]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootY] += size[rootX];
        }
        cnt -= 1;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        UF uf(n);
        for(auto& c : connections) {
            int a = c[0], b = c[1];
            uf.unite(a, b);
        }
        // cout << uf.
        return uf.cnt - 1;
    }
};