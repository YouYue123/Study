// 1150. Check If a Number Is Majority Element in a Sorted Array [E]
// LeetCode check-if-a-number-is-majority-element-in-a-sorted-array

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = lower_bound(nums.begin(), nums.end(), target + 1);
        return it2 - it1 > nums.size() / 2;
    }
};