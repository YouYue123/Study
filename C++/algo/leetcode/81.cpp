#include <bits/stdc++.h>
using namespace std;

// 81. Search in Rotated Sorted Array II [M]
// LeetCode search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        while(end > 0 && nums[0] == nums[end]) {
            end -= 1;
        }
        int left = 0, right = end;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // cout << "rotation point index: " << left << endl;
        if(nums[0] > nums[left]) {
            // cout << "rotation exist" << endl;
            left = left - 1;
        }
        if(nums[0] <= target) {
            right = left;
            left = 0;
        } else {
            left = left + 1;
            right = end;
        }
        // cout << "search from " << "left: " << left << " right: " << right << endl;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(left > end) return false;
        return nums[left] == target;
    }
};