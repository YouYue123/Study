#include <bits/stdc++.h>
using namespace std;

// 715. Range Module [H]
// LeetCode range-module

class RangeModule {
    struct Interval {
        int start, end;
        Interval(int start, int end) : start(start), end(end) {}
    };
    vector<Interval> intervals;

public:
    RangeModule() {}

    void addRange(int left, int right) {
        vector<Interval> ans;
        int n = intervals.size(), cur = 0, i = 0;
        while (i < n) {
            if (intervals[i].end < left) {
                ans.push_back(intervals[i]);
            } else if (intervals[i].start > right) {
                ans.push_back(Interval(left, right));
                break;
            } else {
                left = min(left, intervals[i].start);
                right = max(right, intervals[i].end);
            }
            i++;
        }
        if (i == n) ans.push_back(Interval(left, right));
        while (i < n) ans.push_back(intervals[i++]);
        intervals = ans;
    }

    bool queryRange(int left, int right) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid].start >= right) {
                r = mid - 1;
            } else if (intervals[mid].end <= left) {
                l = mid + 1;
            } else {
                return intervals[mid].start <= left &&
                       intervals[mid].end >= right;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        vector<Interval> result;
        int n = intervals.size(), i = 0;
        while (i < n) {
            if (intervals[i].end <= left) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start >= right) {
                result.push_back(intervals[i]);
            } else {
                if (intervals[i].start < left)
                    result.push_back(Interval(intervals[i].start, left));
                if (intervals[i].end > right)
                    result.push_back(Interval(right, intervals[i].end));
            }
            i++;
        }
        intervals = result;
    }
};