// 2874. Maximum Value of an Ordered Triplet II [M]
// LeetCode maximum-value-of-an-ordered-triplet-ii

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long maxI = max(nums[0], nums[1]);
        long long maxGap = nums[0] - nums[1];
        for(int k = 2; k < nums.size(); k ++) {
            ans = max(ans, maxGap * nums[k]);
            maxGap = max(maxGap, maxI - nums[k]);
            maxI = max(maxI, (long long)nums[k]);
        }
        return ans;
    }
};