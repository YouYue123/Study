#include <bits/stdc++.h>
using namespace std;

// 3733. Minimum Time to Complete All Deliveries [M]
// LeetCode minimum-time-to-complete-all-deliveries

class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        int d0 = d[0];
        int d1 = d[1];
        int r0 = r[0];
        int r1 = r[1];
        long long lcmR = std::lcm(r0, r1);
        auto isValid = [&] (long long h) -> bool{
            long long d0Max = h - h / r0;
            long long d1Max = h - h / r1;
            long long totalMax = h - h / lcmR;
            return d0 <= d0Max  && d1 <= d1Max && ((d0 + d1) <= totalMax);
        };
        long long left = 0;
        long long right = (d0 + d1) * lcmR;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(!isValid(mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};