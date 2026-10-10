#include <bits/stdc++.h>
using namespace std;

// 162. Find Peak Element [M]
// LeetCode find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto isValid = [&] (int x) -> bool {
            return x > 0 && nums[x] > nums[x - 1];
        };
        int left = 0, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};