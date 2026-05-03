// 75. Sort Colors [M]
// LeetCode sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int cur = 0;
        while(cur <= right) {
            if(nums[cur] == 0) {
                swap(nums[cur], nums[left]);
                left += 1;
                cur += 1;
            } else if(nums[cur] == 1) {
                cur += 1;
            } else {
                swap(nums[cur], nums[right]);
                right -= 1;
            }
        }
    }
};