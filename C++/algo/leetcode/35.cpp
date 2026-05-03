#include <bits/stdc++.h>
using namespace std;

// 35. Search Insert Position [E]
// LeetCode search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};