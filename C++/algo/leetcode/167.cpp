// 167. Two Sum II - Input Array Is Sorted [M]
// LeetCode two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] + nums[right] > target) {
                right -= 1;
            } else if(nums[left] + nums[right] < target) {
                left += 1;
            } else {
                return { left + 1, right + 1 };
            }
        }
        return {};
    }
};