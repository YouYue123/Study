#include <bits/stdc++.h>
using namespace std;

// 56. Merge Intervals [M]
// LeetCode merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i ++) {
            if(ans.empty() || ans.back().back() < intervals[i].front()) {
                ans.push_back(intervals[i]);
            } else {
                ans.back().back() = max(ans.back().back(), intervals[i].back());
            }
        }
        return ans;
    }
};