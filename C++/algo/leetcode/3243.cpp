#include <bits/stdc++.h>
using namespace std;

// 3243. Shortest Distance After Road Addition Queries I [M]
// LeetCode shortest-distance-after-road-addition-queries-i

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n, vector<int>());
        for(int i = 0; i < n - 1; i ++) g[i].push_back(i + 1);
        vector<int> ans;
        vector<int> dist(n, 0);
        for(int i = 0; i < n; i ++) dist[i] = i;
        for(auto& query : queries) {
            int u = query[0], v = query[1];
            g[u].push_back(v);
            if(dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                queue<int> q;
                q.push(v);
                while(!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for(int nxt : g[cur]) {
                        if(dist[cur] + 1 < dist[nxt]) {
                            dist[nxt] = dist[cur] + 1;
                            q.push(nxt);
                        }
                    }
                }
            }
            ans.push_back(dist[n - 1]);
           
        }
        return ans;
    }
};