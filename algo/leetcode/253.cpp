#include <bits/stdc++.h>
using namespace std;

// 253. Meeting Rooms II [M]
// LeetCode meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;   
        pq.push(intervals[0][1]);
        for(int i = 1; i < n; i ++) {
            if(!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};