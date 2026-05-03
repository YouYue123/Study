#include <bits/stdc++.h>
using namespace std;

// 990. Satisfiability of Equality Equations [M]
// LeetCode satisfiability-of-equality-equations

class UF {
vector<int> parent;
public:
    UF(int n ) {
        parent.resize(n);
        for(int i = 0; i < n ; i++) parent[i] = i;
    }
    void union_(int p, int q){
        int rootP = findRoot(p);
        int rootQ= findRoot(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
    }

    int findRoot(int x) {
        // cout << "x: " << x << endl;
        if(x == parent[x]) return x;
        int root = findRoot(parent[x]);
        parent[x] = root;
        return root;
    }

    bool connected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        auto uf = UF(26);
        for(string e: equations) {
            if(!e.contains('!')) uf.union_(e[0] - 'a', e.back() - 'a');
        }
        for(string e: equations) {
            if(e.contains('!')) {
                if(uf.connected(e[0] - 'a', e.back() - 'a')) return false;
            }
        }
        return true;
    }
};