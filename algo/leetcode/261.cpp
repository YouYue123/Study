#include <bits/stdc++.h>
using namespace std;

// 261. Graph Valid Tree [M]
// LeetCode graph-valid-tree

struct UF {
    vector<int> parent;
    int size;
    vector<int> rank;
    UF(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        rank.assign(n, 1);
        size = n;
    }
    
    void unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if(rootX == rootY) return ;
        if(rank[rootY] > rank[rootX]) {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        } else {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        size -= 1;
    }

    int findRoot (int x) {
        if(parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool isConnect(int x, int y) {
        return findRoot(x) == findRoot(y);
    }

};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        UF uf(n);
        for(auto& e : edges) {
            int a = e[0], b = e[1];
            if(uf.isConnect(a, b)) return false;
            uf.unite(a, b);
        }
        return true;
    }
};