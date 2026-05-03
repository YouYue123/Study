// 452. Minimum Number of Arrows to Burst Balloons [M]
// LeetCode minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [&] (auto& a, auto& b) {
            return a[1] < b[1];
        });
        int curMax = points[0][1];
        int ans = 1;
        for(int i = 1; i < n; i ++) {
            auto& p = points[i];
            int s = p[0], e = p[1];
            if(s > curMax) {
                curMax = e;
                ans += 1;
            }
        }
        return ans;
    }
};