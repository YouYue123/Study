#include <bits/stdc++.h>
using namespace std;

// 3594. Minimum Time to Transport All Individuals [H]
// LeetCode minimum-time-to-transport-all-individuals

struct State {
    double time;
    int mask;
    int stage;
    int boat;
    bool operator > (const State& other) const {
        return time > other.time;
    }
    bool operator < (const State& other) const {
        return time < other.time;
    }
};
class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(k == 1 && n > 1) return -1;
        int finalMask = (1 << n) - 1;

        // dist[mask][stage][boat]
        vector<vector<vector<double>>> dist(1 << n, vector<vector<double>>(m, vector<double>(2, DBL_MAX)));
        priority_queue<State, vector<State>, greater<>> pq;
        dist[0][0][0] = 0.0;
        pq.emplace(0.0, 0, 0, 0);
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if(cur.time > dist[cur.mask][cur.stage][cur.boat]) continue;
            if(cur.boat == 0) {
                vector<int> atBaseIndices;
                for(int i = 0; i < n; i ++) {
                    bool isIAtBase = ((cur.mask >> i) & 1) == 0;
                    if(isIAtBase) atBaseIndices.push_back(i);
                }
                int baseCnt = atBaseIndices.size();
                for(int gSize = 1; gSize <= k && gSize <= baseCnt; gSize ++) {
                    vector<int> curGIndices;
                    function<void(int, int)> comb = [&](int startIdx, int cnt) {
                        if(cnt == gSize) {
                            int gMask = 0;
                            int gMaxTime = 0;
                            for(int idx : curGIndices) {
                                int pIdx = atBaseIndices[idx];
                                gMask |= (1 << pIdx);
                                gMaxTime = max(gMaxTime, time[pIdx]);
                            }
                            double crossTime = mul[cur.stage] * (double)gMaxTime;
                            int newMask = cur.mask | gMask;
                            int newStage = (cur.stage + (int)floor(crossTime)) % m;
                            double newTime = cur.time + crossTime;
                            if(newTime < dist[newMask][newStage][1]) {
                                dist[newMask][newStage][1] = newTime;
                                pq.emplace(newTime, newMask, newStage, 1);
                                return;
                            }
                        }
                        for(int i = startIdx; i < baseCnt; i ++) {
                            curGIndices.push_back(i);
                            comb(i + 1, cnt + 1);
                            curGIndices.pop_back();
                        }
                    };
                    comb(0, 0);
                }
            } else {
                if(cur.mask == finalMask) continue;
                for(int i = 0; i < n; i ++) {
                    bool isIAtDest = (cur.mask >> i) & 1;
                    if(isIAtDest) {
                        double returnTime = mul[cur.stage] * (double)time[i];
                        int newMask = cur.mask & ~(1 << i);
                        int newStage = (cur.stage + (int)floor(returnTime)) % m;
                        double newTime = returnTime + cur.time;
                        if(newTime < dist[newMask][newStage][0]) {
                            dist[newMask][newStage][0] = newTime;
                            pq.emplace(newTime, newMask, newStage, 0);
                        }
                    }
                }
            }
        
        }
        double ans = DBL_MAX;
        for(int i = 0; i < m; i ++) {
            ans = min(ans, dist[finalMask][i][1]);
        }
        return ans == DBL_MAX ? -1 : ans;
    }
};