#include <bits/stdc++.h>
using namespace std;

// 1135. Connecting Cities With Minimum Cost [M]
// LeetCode connecting-cities-with-minimum-cost

struct UF {
    int count;
    vector<int> parent;
    UF(int n ) {
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
        return parent[x] = findRoot(parent[x]);
    }
    bool isConnected(int p, int q) { return findRoot(p) == findRoot(q); }
};

struct Edge {
    int from;
    int to;
    int cost;
    bool operator>(const Edge& other) const {
        return cost > other.cost;
    }

};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UF uf(n + 1);
        priority_queue<Edge, vector<Edge>, greater<>> pq;
        for(auto& c : connections) {
            pq.push(Edge(c[0], c[1], c[2]));
        }
        int ans = 0;
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(uf.isConnected(cur.from, cur.to)) continue;
            ans += cur.cost;
            uf.union_(cur.from, cur.to);
        }
        return uf.count == 2 ? ans : -1;
    }
};