#include <bits/stdc++.h>
using namespace std;

// 2508. Add Edges to Make Degrees of All Nodes Even [H]
// LeetCode add-edges-to-make-degrees-of-all-nodes-even

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0) ;
        unordered_map<int, unordered_set<int>> g;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            degree[u] += 1;
            degree[v] += 1;
            g[u].insert(v);
            g[v].insert(u);
        }
        vector<int> odd_nodes;
        for(int i = 1; i <= n; i ++) {
            if(degree[i] %  2 == 1) odd_nodes.push_back(i);
        }
        if(odd_nodes.size() == 0) return true;
        if(odd_nodes.size() == 2) {
            int a = odd_nodes[0], b = odd_nodes[1];
            if(!g[a].contains(b)) return true;
            for(int i = 1; i <= n; i ++) {
                if(i != a && i != b && !g[i].contains(a) && !g[i].contains(b)) {
                    return true;
                }
            }
        }
        if(odd_nodes.size() == 4) {
            int a = odd_nodes[0], b = odd_nodes[1], c = odd_nodes[2], d = odd_nodes[3];
            if(!g[a].contains(b) && !g[c].contains(d)) return true;
            if(!g[a].contains(c) && !g[b].contains(d)) return true;
            if(!g[a].contains(d) && !g[b].contains(c)) return true;
        }
        return false;
    }
};