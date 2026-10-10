#include <bits/stdc++.h>
using namespace std;

// 435. Non-overlapping Intervals [M]
// LeetCode non-overlapping-intervals

int constexpr INF = 0x3f3f3f3f3f;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (auto& a, auto& b) {
            return a[1] < b[1];
        });
        
        int cnt = 0, cur_end = -INF;
        for(auto& interval : intervals) {
            if(interval[0] >= cur_end) {
                cur_end = interval[1];
                cnt += 1;
            }
        }
        return intervals.size() - cnt;

    }
};