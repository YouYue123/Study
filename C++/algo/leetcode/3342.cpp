#include <bits/stdc++.h>
using namespace std;

// 3342. Find Minimum Time to Reach Last Room II [M]
// LeetCode find-minimum-time-to-reach-last-room-ii

struct State {
    int i;
    int j;
    int time;
    int cost;
    State(int _i, int _j, int _time, int _cost): i(_i),j(_j), time(_time), cost(_cost) {}
    bool operator< (const State& other) {
        return time < other.time;
    }
    bool operator> (const State& other) {
        return time > other.time;
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<State, vector<State>, greater<>> pq;
        vector<vector<int>> distTo(m, vector<int>(n, INT_MAX));
        distTo[0][0] = 0;
        pq.push(State(0, 0, 0, 1));
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            // cout << cur.i << " " << cur.j << " " << cur.time << " " << cur.cost << endl;
            if(cur.i == m - 1 && cur.j == n - 1) return cur.time;
            for(auto& d : dirs) {
                int ni = cur.i + d.first;
                int nj = cur.j + d.second;
                if(ni < 0 || ni >= m) continue;
                if(nj < 0 || nj >= n) continue;
                int nTime = max(cur.time, moveTime[ni][nj]) + cur.cost;
                // cout << nTime << endl;
                if(distTo[ni][nj] > nTime) {
                    distTo[ni][nj] = nTime;
                    pq.push(State(ni, nj, nTime, cur.cost == 1 ? 2 : 1));
                }
            }
        }
        return distTo[m - 1][n - 1];
    }
};