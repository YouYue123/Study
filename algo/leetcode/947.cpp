#include <bits/stdc++.h>
using namespace std;

// 947. Most Stones Removed with Same Row or Column [M]
// LeetCode most-stones-removed-with-same-row-or-column

class UF {
public:
    int count;
    vector<int> parent;
    UF(int n) {
        count = n;
        parent.resize(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
    }
    void union_ (int p, int q) {
        int rootP = findRoot(p);
        int rootQ = findRoot(q);
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UF uf = UF(n);
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.union_(i, j);
                }
            }
        }
        return n - uf.count;
    }
};