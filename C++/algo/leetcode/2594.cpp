#include <bits/stdc++.h>
using namespace std;

// 2594. Minimum Time to Repair Cars [M]
// LeetCode minimum-time-to-repair-cars

class Solution {
public:
    bool isValid(long long givenTime, vector<int>& ranks, int cars) {
        long long sum = 0;
        for(int r : ranks) {
            sum += sqrt(givenTime / r);
        }
        return sum >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long)cars * cars * (*min_element(ranks.begin(), ranks.end()));
        // cout << left << " " << right << endl;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(isValid(mid, ranks, cars)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};