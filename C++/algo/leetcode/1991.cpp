// 1991. Find the Middle Index in Array [E]
// LeetCode find-the-middle-index-in-array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> preSum(nums.size() + 1, 0);
        for(int i = 1; i < preSum.size(); i ++) {
            preSum[i] = nums[i - 1] + preSum[i - 1];
        }
        for(int i = 0; i < nums.size(); i ++) {
            int leftSum = preSum[i];
            int rightSum = preSum[preSum.size() - 1] - preSum[i + 1];
            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};