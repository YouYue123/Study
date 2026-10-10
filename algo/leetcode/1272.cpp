#include <bits/stdc++.h>
using namespace std;

// 1272. Remove Interval [M]
// LeetCode remove-interval

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i ++) {
            if(intervals[i][0] > toBeRemoved[1] || intervals[i][1] < toBeRemoved[0]) {
                // No overlaps
                ans.push_back({intervals[i][0], intervals[i][1]});
            } else {
                // left overlap
                if(intervals[i][0] < toBeRemoved[0]) {
                    ans.push_back({intervals[i][0], toBeRemoved[0]});
                }
                // right overlap
                if(intervals[i][1] > toBeRemoved[1]) {
                    ans.push_back({toBeRemoved[1], intervals[i][1]});
                }
            }
        }
        return ans;
    }
};