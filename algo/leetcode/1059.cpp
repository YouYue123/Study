#include <bits/stdc++.h>
using namespace std;

// 1059. All Paths from Source Lead to Destination [M]
// LeetCode all-paths-from-source-lead-to-destination

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for(auto& e : edges) {
            graph[e[1]].push_back(e[0]);
            indegree[e[0]] += 1;
        }
        if(indegree[destination] != 0) return false;
        queue<int> q;
        q.push(destination);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(cur == source) return true;
            for(int next : graph[cur]) {
                indegree[next] -= 1;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return false;
    }
};