#include <bits/stdc++.h>
using namespace std;

// 3169. Count Days Without Meetings [M]
// LeetCode count-days-without-meetings

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        vector<int> prev = meetings[0];
        ans += meetings[0][0] - 1;
        for(int i = 1; i < meetings.size(); i ++) {
            int prevStart = prev[0];
            int prevEnd = prev[1];
            // cout << "prevStart: " << prevStart << " prevEnd: " << prevEnd << endl;
            int nextStart = meetings[i][0];
            int nextEnd = meetings[i][1];
            // cout << "nextStart: " << nextStart << " nextEnd: " << nextEnd << endl;
            if(nextStart > prevEnd) {
                ans += nextStart - prevEnd - 1;
                prev = meetings[i];
            }
            prev[1] = max(nextEnd, prev[1]);
        }
        if(prev[1] < days) {
            ans += days - prev[1];
        }
        return ans;
    }
};