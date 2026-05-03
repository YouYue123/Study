// 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target [M]
// LeetCode maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<int> dp(nums.size() + 1, 0);
        unordered_map<int, int> dict;
        dict[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            int comple = sum - target;
            if(dict.contains(comple)) {
                int prevIdx = dict[comple];
                ans = max(ans, dp[prevIdx + 1] + 1);
            }
            dp[i + 1] = ans;
            dict[sum] = i;
        }
        return ans;
    }
};