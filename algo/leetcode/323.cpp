#include <bits/stdc++.h>
using namespace std;

// 323. Number of Connected Components in an Undirected Graph [M]
// LeetCode number-of-connected-components-in-an-undirected-graph

class UF {
public:
int count;
vector<int> parent;
    UF(int n) {
        count = n;
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void union_(int p, int q) {
        int rootP = findRoot(p);
        int rootQ= findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
        count -= 1;
    }
    int findRoot(int x) {
        if(parent[x] == x) return x;
        int root = findRoot(parent[x]);
        parent[x] = root;
        return root;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf = UF(n);
        for(vector<int>& edge : edges) {
            uf.union_(edge[0], edge[1]);
        }        
        return uf.count;
    }
};