#include <bits/stdc++.h>
using namespace std;

// 1283. Find the Smallest Divisor Given a Threshold [M]
// LeetCode find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int threshold) {
        long long sum = 0;
        for(int num : nums) sum += ceil((double)num / mid);
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;
        while(left < right) {   
            int mid = left + (right - left) / 2;
            if(isValid(mid, nums, threshold)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};