#include <bits/stdc++.h>
using namespace std;

// 1870. Minimum Speed to Arrive on Time [M]
// LeetCode minimum-speed-to-arrive-on-time

class Solution {
public:
    bool isValid(int givenSpeed, vector<int>& dist, double hour) {
        double requiredHour = 0.0;
        for(int d : dist) {
            requiredHour = (double)ceil(requiredHour);
            requiredHour += (double)d / givenSpeed;
            // cout << requiredHour << endl;
        }
        // cout << givenSpeed << " " << requiredHour << endl;
        return requiredHour <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, dist, hour)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return isValid(left, dist, hour) ? left : -1;
    }
};