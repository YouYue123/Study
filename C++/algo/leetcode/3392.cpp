// 3392. Count Subarrays of Length Three With a Condition [E]
// LeetCode count-subarrays-of-length-three-with-a-condition

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int left = 0, right = 2;
        int ans = 0;
        while(right < nums.size()) {
            if(nums[left] + nums[right] == (double)nums[left + 1] / 2) ans += 1;
            left += 1;
            right += 1;
        }
        return ans;
    }
};