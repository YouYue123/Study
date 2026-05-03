#include <bits/stdc++.h>
using namespace std;

// 1976. Number of Ways to Arrive at Destination [M]
// LeetCode number-of-ways-to-arrive-at-destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> graph;
        for(vector<int>& r : roads) {
            graph[r[0]].push_back({ r[1], r[2] });
            graph[r[1]].push_back({ r[0], r[2] });
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        q.push({ 0, 0 });
        vector<long long> shortestDist(n, LLONG_MAX);
        vector<int> pathCount(n, 0);
        shortestDist[0] = 0;
        pathCount[0] = 1;
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();
            long long curDist = cur.first;
            int curNode = cur.second;
            for(auto& [nextNode, roadDist] : graph[curNode]) {
                if(curDist + roadDist < shortestDist[nextNode]) {
                    shortestDist[nextNode] = curDist + roadDist;
                    pathCount[nextNode] = pathCount[curNode];
                    q.push({ shortestDist[nextNode], nextNode });
                } else if ((curDist + roadDist) == shortestDist[nextNode]){
                    pathCount[nextNode] = (pathCount[nextNode] + pathCount[curNode]) % MOD;
                }
            }
        }
        return pathCount[n - 1];
    }
};