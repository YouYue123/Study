#include <bits/stdc++.h>
using namespace std;

// 1266. Minimum Time Visiting All Points [E]
// LeetCode minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto dist = [&](vector<int> p1, vector<int> p2) {
            return max(abs(p2[0] - p1[0]), abs(p2[1] - p1[1]));
        };
        int ans = 0;
        for(int i = 1; i < n; i ++) {
            ans += dist(points[i - 1], points[i]);
        }
        return ans;
    }
};