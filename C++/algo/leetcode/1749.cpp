// 1749. Maximum Absolute Sum of Any Subarray [M]
// LeetCode maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = INT_MIN;
        int minSum = 0;
        int maxSum = 0;
        for(int num : nums) {
            minSum = min(num, num + minSum);
            maxSum = max(num, num + maxSum);
            ans = max({
                ans, abs(maxSum), abs(minSum),
            });
        }
        return ans;
    }
};