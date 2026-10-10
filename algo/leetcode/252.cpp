#include <bits/stdc++.h>
using namespace std;

// 252. Meeting Rooms [E]
// LeetCode meeting-rooms

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n - 1; i ++) {
            auto& cur = intervals[i];
            auto& nxt = intervals[i + 1];
            if(cur.back() > nxt.front()) return false; 
        }
        return true;
    }
};