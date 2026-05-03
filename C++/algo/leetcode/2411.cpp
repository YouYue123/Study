// 2411. Smallest Subarrays With Maximum Bitwise OR [M]
// LeetCode smallest-subarrays-with-maximum-bitwise-or

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < nums.size(); i ++) {
            int cur = nums[i];
            ans[i] = 1;
            for(int j = i - 1; j >= 0; j --) {
                if((nums[j] | cur) == nums[j]) break;
                nums[j] |= cur;
                ans[j] = i - j + 1;
            }
        }
        return ans;
    }
};