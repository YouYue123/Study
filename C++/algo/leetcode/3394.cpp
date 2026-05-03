#include <bits/stdc++.h>
using namespace std;

// 3394. Check if Grid can be Cut into Sections [M]
// LeetCode check-if-grid-can-be-cut-into-sections

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xIntervals;
        vector<vector<int>> yIntervals;
        for(vector<int>& r: rectangles) {
            xIntervals.push_back({r[0], r[2]});
            yIntervals.push_back({r[1], r[3]});
        }
        sort(xIntervals.begin(), xIntervals.end());
        sort(yIntervals.begin(), yIntervals.end());
        int prevEnd = 0;
        int count = 0;
        for(vector<int>& interval : xIntervals) {
            if(interval[0] >= prevEnd) count += 1;
            prevEnd = max(interval[1], prevEnd);
        }
        // cout << "xCut: " << count << endl;
        if(count >= 3) return true;
        prevEnd = 0;
        count = 0;
        for(vector<int>& interval: yIntervals) {
            if(interval[0] >= prevEnd) count += 1;
            prevEnd = max(interval[1], prevEnd);
        }
        // cout << "yCut: " << count << endl;
        if(count >= 3) return true;
        return false;
    }
};