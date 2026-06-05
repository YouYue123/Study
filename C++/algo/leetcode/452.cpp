#include <bits/stdc++.h>
using namespace std;

// 452. Minimum Number of Arrows to Burst Balloons [M]
// LeetCode minimum-number-of-arrows-to-burst-balloons

long long constexpr INF = 0x3f3f3f3f3f3f3f;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&] (auto& a, auto& b) {
            return a[1] < b[1];
        });
        long long ans = 0, cur_end = -INF;
        for(auto& p : points) {
            if(p[0] > cur_end) {
                cur_end = p[1];
                ans += 1;
            }
        }
        return ans;
    }
};