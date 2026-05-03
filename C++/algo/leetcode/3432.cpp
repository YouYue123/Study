// 3432. Count Partitions with Even Sum Difference [E]
// LeetCode count-partitions-with-even-sum-difference

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int preSum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        for(int i = 0; i < n - 1; i ++) {
            preSum += nums[i];
            if(abs(preSum - (totalSum - preSum)) % 2 == 0) ans += 1;
            
        }
        return ans;
    }
};