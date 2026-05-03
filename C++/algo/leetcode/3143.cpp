#include <bits/stdc++.h>
using namespace std;

// 3143. Maximum Points Inside the Square [M]
// LeetCode maximum-points-inside-the-square

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int ans = 0;
        auto isValid = [&] (int size) {
            int visited = 0;
            for(int i = 0; i < points.size(); i ++) {
                if (abs(points[i][0]) <= size && abs(points[i][1]) <= size) {
                    int cIdx= s[i] - 'a';
                    if(visited & (1 << cIdx)) return false;
                    visited |= 1 << cIdx;
                }
            }
            ans = __builtin_popcount(visited);
            return true;
        };
        int left = 0, right = 1e9 + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return ans;
    }
};