// 1498. Number of Subsequences That Satisfy the Given Sum Condition [M]
// LeetCode number-of-subsequences-that-satisfy-the-given-sum-condition

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        vector<long long> power(nums.size(), 0);
        power[0] = 1;
        for(int i = 1; i < nums.size(); i ++) power[i] = power[i - 1] * 2 % MOD;
        while(left <= right) {
            if(nums[left] + nums[right] > target) {
                right -= 1;
            } else {
                ans = ((long long)ans + power[right - left]) % MOD;
                left += 1;
            }
        }
        return ans;
    }
};