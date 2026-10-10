#include <bits/stdc++.h>
using namespace std;

// 34. Find First and Last Position of Element in Sorted Array [M]
// LeetCode find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // lower_bound
        int left = -1, right = n;
        vector<int> ans;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if(left + 1 < n && nums[left + 1] == target) ans.push_back(left + 1);
        else return {-1, -1};
        // upper_bound
        left = -1, right = n;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ans.push_back(left);
        return ans;
    }
};