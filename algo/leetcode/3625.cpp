#include <bits/stdc++.h>
using namespace std;

// 3625. Count Number of Trapezoids II [H]
// LeetCode count-number-of-trapezoids-ii

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<double, map<double, int>> cnt;
        unordered_map<int, map<double, int>> cnt2;
        int n = points.size();
        for(int i = 0; i < n; i ++) {
            int x = points[i][0], y= points[i][1];
            for(int j = 0; j < i; j ++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x - x2, dy = y - y2;
                double k = dx ? 1.0 * dy / dx : DBL_MAX;
                double b = dx ? 1.0 * (y * dx - x * dy) / dx : x;
                cnt[k][b] += 1;
                // Compress
                int mid = (x + x2 + 2000) << 16 | (y + y2 + 2000);
                cnt2[mid][k] += 1;
            }
        }
        int ans = 0;
        for(auto& [_, m] : cnt) {
            int s = 0;
            for(auto& [_, c] : m ) {
                ans += c * s;
                s += c;
            }
        }
        for(auto& [_, m] : cnt2) {
            int s = 0;
            for(auto& [_, c] : m) {
                ans -= s * c;
                s += c;
            }
        }
        return ans;
    }
};