#include <bits/stdc++.h>
using namespace std;

// 435. Non-overlapping Intervals [M]
// LeetCode non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&] (auto& a, auto& b) {
            return a[1] < b[1];
        });
        int cnt = 1;
        int end = intervals[0][1];
        for(int i = 1; i < n; i ++) {
            if(intervals[i][0] >= end) {
                cnt += 1;
                end = intervals[i][1];
            }
        }
        return n - cnt;
    }
};