// 2826. Sorting Three Groups [M]
// LeetCode sorting-three-groups

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int dp[4] = {};
        for(int x : nums) {
            int maxLen = 0;
            for(int i = 1; i <= x; i ++) maxLen = max(dp[i], maxLen);
            dp[x] = maxLen + 1;
        }
        int maxLen = 0;
        for(int len : dp) {
            maxLen = max(maxLen, len);
        }
        return nums.size() - maxLen;
    }
};