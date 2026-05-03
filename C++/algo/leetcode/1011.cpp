#include <bits/stdc++.h>
using namespace std;

// 1011. Capacity To Ship Packages Within D Days [M]
// LeetCode capacity-to-ship-packages-within-d-days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        auto isValid = [&] (int x) -> bool {
            int days_required = 1;
            int cap = x;
            for(int weight : weights) {
                if(weight > x) return false;
                if(weight <= cap) {
                    cap -= weight;
                } else {
                    days_required += 1;
                    cap = x;
                    cap -= weight;
                }
            }
            // cout << "x: " << x << " days_required: " << days_required << endl;
            return days_required <= days;
        };

        int left = 0, right = accumulate(weights.begin(), weights.end(), 0);
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            // cout << isValid(mid) << endl;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left + 1;
    }
};