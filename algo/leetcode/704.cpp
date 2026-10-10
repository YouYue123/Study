#include <bits/stdc++.h>
using namespace std;

// 704. Binary Search [E]
// LeetCode binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = -1, right = nums.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) /2;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[left + 1] == target ? left + 1 : -1;
    }
};