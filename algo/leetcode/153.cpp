#include <bits/stdc++.h>
using namespace std;

// 153. Find Minimum in Rotated Sorted Array [M]
// LeetCode find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(nums[0] > nums[left]) {
            return nums[left];
        } else {
            return nums[0];
        }   
    }
};