// 1493. Longest Subarray of 1's After Deleting One Element [M]
// LeetCode longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int del = 0;
        int ans = 0;
        while(right < n) {
            if(nums[right] == 0) del += 1;
            while(del > 1) {
                if(nums[left] == 0) del -= 1;
                left += 1;
            }
            ans = max(ans, right - left);
            right += 1;
        }
        return ans;
    }
};