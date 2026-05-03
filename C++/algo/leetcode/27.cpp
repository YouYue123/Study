// 27. Remove Element [E]
// LeetCode remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() == 1) return nums[0] == val ? 0 : 1;
        int right = nums.size() - 1;
        int left = 0;
        while(left <= right && nums[right] == val) right -= 1;
        while(left <= right) {
            if(nums[left] == val) {
                swap(nums[left], nums[right]);
                while(nums[right] == val) right -= 1;
            }
            left += 1;
        }
        // cout << right << endl;
        return right + 1;
    }
};