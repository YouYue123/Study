#include <bits/stdc++.h>
using namespace std;

// 2529. Maximum Count of Positive Integer and Negative Integer [E]
// LeetCode maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int posCount = 0;
        if(nums[left] > 0) posCount = nums.size() - left;
        left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int negCount = 0;
        if(left - 1 >= 0) negCount = left;
        return max(posCount, negCount); 
    }
};