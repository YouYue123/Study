#include <bits/stdc++.h>
using namespace std;

// 1466. Reorder Routes to Make All Paths Lead to the City Zero [M]
// LeetCode reorder-routes-to-make-all-paths-lead-to-the-city-zero

struct Edge {
    int nextNode;
    bool forward;
    Edge(int _nextNode, bool _forward): nextNode(_nextNode), forward(_forward) {};
};
class Solution {
public:
    unordered_map<int, vector<Edge>> graph;
    unordered_map<int, bool> visited;
    int ans = 0;
    void dfs(int cur) {
        cout << cur << endl;
        visited[cur] = true;
        for(Edge edge : graph[cur]) {
            if(visited[edge.nextNode]) continue;
            if(edge.forward) {
                // cout << "forward!" << endl;
                ans += 1;
            }
            dfs(edge.nextNode);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(vector<int>& con : connections) {
            graph[con[0]].push_back(Edge(con[1], true));
            graph[con[1]].push_back(Edge(con[0], false));
        }
        dfs(0);
        return ans;
    }
};