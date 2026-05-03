// 2419. Longest Subarray With Maximum Bitwise AND [M]
// LeetCode longest-subarray-with-maximum-bitwise-and

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int ans = 0, cnt = 0;
        for(int num : nums) {
            if(num == maxEle) cnt += 1;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};