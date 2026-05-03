// 918. Maximum Sum Circular Subarray [M]
// LeetCode maximum-sum-circular-subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxF = 0;
        int maxS = INT_MIN;
        int minF = 0;
        int minS = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ;i ++) {
            maxF = max(maxF, 0) + nums[i];
            maxS = max(maxF, maxS);
            minF = min(minF, 0) + nums[i];
            minS = min(minS, minF);
            sum += nums[i];
        }
        return maxS < 0 ? maxS : max(maxS, sum - minS);
    }
};