// 3738. Longest Non-Decreasing Subarray After Replacing at Most One Element [M]
// LeetCode longest-non-decreasing-subarray-after-replacing-at-most-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n, 1);
        vector<int> pre(n, 1);
        int ans = 1;
        for(int i = 1, j = n - 2; i < n; i ++, j --) {
            if(nums[i] >= nums[i - 1]) pre[i] = pre[i - 1] + 1;
            if(nums[j + 1] >= nums[j]) suf[j] = suf[j + 1] + 1;
        }
        for(int i = 0; i < n; i ++) {
            if(i > 0) ans = max(ans, pre[i - 1] + 1);
            if(i < n - 1) ans = max(ans, suf[i + 1] + 1);
            if(i > 0 && i < n - 1 && nums[i - 1] <= nums[i + 1]) {
                ans = max(ans, pre[i - 1] + 1 + suf[i + 1]);
            }
        }
        return ans;
    }
};