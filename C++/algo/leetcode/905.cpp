// 905. Sort Array By Parity [E]
// LeetCode sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] % 2 == 0) {
                left += 1;
                continue;
            }
            if(nums[right] % 2 == 1) {
                right -= 1;
                continue;
            }
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};