#include <bits/stdc++.h>
using namespace std;

// 2360. Longest Cycle in a Graph [H]
// LeetCode longest-cycle-in-a-graph

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector indegree(n, 0);
        for(int i = 0; i < n; i ++) {
            if(edges[i] != -1) indegree[edges[i]] += 1;
        }
        // cout << "lol" << endl;
        queue<int> q;
        for(int i = 0; i < n; i ++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector visited(n, false);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            int nxt = edges[cur];
            if(nxt == -1) continue;
            indegree[nxt] -= 1;
            if(indegree[nxt] == 0) q.push(nxt);
        }
        int ans = -1;
        for(int i = 0; i < n; i ++) {
            if(!visited[i]) {
                int cnt = 0;
                int cur = i;
                while(!visited[cur]) {
                    visited[cur] = true;
                    cnt += 1;
                    cur = edges[cur];
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};