// 2495. Number of Subarrays Having Even Product [M]
// LeetCode number-of-subarrays-having-even-product

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int n = nums.size();
        // dp[i][0]表示以nums[i]结尾的乘积为偶数的子数组个数
        // dp[i][1]表示以nums[i]结尾的乘积为奇数的子数组个数
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        
        // 初始化第一个元素
        if(nums[0] % 2 == 0) {
            dp[0][0] = 1;
            dp[0][1] = 0;
        } else {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        
        long long ans = dp[0][0]; // 初始化为第一个元素的偶数情况
        
        for(int i = 1; i < n; i++) {
            if(nums[i] % 2 == 0) {
                // 当前是偶数：无论前面是什么，乘积都是偶数
                // +1表示只包含当前元素的子数组
                dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1;
                dp[i][1] = 0;
            } else {
                // 当前是奇数：
                // 乘积为偶数的情况 = 前面乘积为偶数的情况
                // 乘积为奇数的情况 = 前面乘积为奇数的情况 + 1(单独当前元素)
                // +1表示只包含当前元素的子数组
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
            ans += dp[i][0]; // 累加以当前元素结尾的偶数乘积子数组数
        }
        
        return ans;
    }
};