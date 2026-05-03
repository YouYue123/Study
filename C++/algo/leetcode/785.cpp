#include <bits/stdc++.h>
using namespace std;

// 785. Is Graph Bipartite? [M]
// LeetCode is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector color(n, 0);
        for(int i = 0; i < n; i ++) {
            if(color[i] != 0) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for(int nxt : graph[cur]) {
                    if(color[nxt] == 0) {
                        color[nxt] = -color[cur];
                        q.push(nxt);
                    } else if(color[nxt] == color[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};