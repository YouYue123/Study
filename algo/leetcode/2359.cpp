#include <bits/stdc++.h>
using namespace std;

// 2359. Find Closest Node to Given Two Nodes [M]
// LeetCode find-closest-node-to-given-two-nodes

class Solution {
public:
    vector<vector<int>> maxDist;
    vector<int> visited;
    void dfs(vector<int>& edges, int from, int node, int dist) {
        // cout << from << " " << node << endl;
        if(visited[node]) return;
        visited[node] = true;
        int n = edges.size();
        int next = edges[node];
        maxDist[node][from] = min(maxDist[node][from], dist);
        if(next == -1) return;
        dfs(edges, from, next, dist + 1);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        maxDist.assign(n, vector<int>(2, INT_MAX));
        visited.assign(n, false);
        dfs(edges, 0, node1, 0);
        visited.assign(n, false);
        dfs(edges, 1, node2, 0);
        // for(int i = 0; i < n ; i ++) {
        //     cout << "i: " << i << " dist: " << maxDist[i][0] << " " << maxDist[i][1] << endl;
        // }
        // cout << endl;
        int ans = -1;
        int curMin = INT_MAX;
        for(int i = 0; i < n; i ++) {
            int dist = max(maxDist[i][0], maxDist[i][1]);
            if(curMin > dist) {
                curMin = dist;
                ans = i;
            }
        }
        return ans;
    }
};