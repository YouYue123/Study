#include <bits/stdc++.h>
using namespace std;

// 759. Employee Free Time [H]
// LeetCode employee-free-time

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> intervals;
        for(auto& s : schedule) {
            for(auto& interval : s) {
                intervals.push_back(interval);
            }
        }
        sort(intervals.begin(), intervals.end(), [&] (auto& a, auto& b) {
            return a.start < b.start;
        });
        vector<Interval> rev_ans;
        for(auto& interval : intervals) {
            if(rev_ans.empty() || rev_ans.back().end < interval.start) {
                rev_ans.push_back(interval);
            } else {
                rev_ans.back().end = max(rev_ans.back().end, interval.end);
            }
        }
        vector<Interval> ans;
        // if(rev_ans.size() > 0 && rev_ans.front().start > 1) {
        //     ans.push_back(Interval(1, rev_ans.front().start));
        // }
        for(int i = 0; i < rev_ans.size() - 1; i ++) {
            ans.push_back(Interval(rev_ans[i].end, rev_ans[i + 1].start));
        }
        return ans;
    }
};