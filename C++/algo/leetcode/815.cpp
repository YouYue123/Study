#include <bits/stdc++.h>
using namespace std;

// 815. Bus Routes [H]
// LeetCode bus-routes

int constexpr INF = 0x3f3f3f3f;
struct Node {
    int busIdx;
    int cnt;
    bool operator>(const Node& other) {
        return cnt > other.cnt;
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target) return 0;
        unordered_map<int, unordered_set<int>> g;
        for(int i = 0; i < n; i ++) {
            for(int route : routes[i]) {
                g[i].insert(route);
            }
        }
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector dist(n, INF);
        for(int i = 0; i < n; i++) {
            if(g[i].contains(source)) {
                dist[i] = 1;
                pq.emplace(i, 1);
            }
        }
        auto hasOverLap = [&] (int i, int j) {
            for(int item : g[i]) {
                if(g[j].contains(item)) return true;
            }
            return false;
        };
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(g[cur.busIdx].contains(target)) break;
            for(int nxtBusIdx = 0; nxtBusIdx < n; nxtBusIdx ++) {
                if(nxtBusIdx == cur.busIdx) continue;
                if(!hasOverLap(nxtBusIdx, cur.busIdx)) continue;
                int nxtCnt = cur.cnt + 1;
                if(nxtCnt >= dist[nxtBusIdx]) continue;
                dist[nxtBusIdx] = nxtCnt;
                pq.emplace(nxtBusIdx, nxtCnt);
            }
        }
        // for(int i = 0; i < n; i ++) {
        //     cout << dist[i] << endl;
        // }
        int ans = INF;
        for(int i = 0; i < n; i ++) {
            if(g[i].contains(target)) {
                ans = min(ans, dist[i]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};