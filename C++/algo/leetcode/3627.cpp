// 3627. Maximum Median Sum of Subsequences of Size 3 [M]
// LeetCode maximum-median-sum-of-subsequences-of-size-3

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(int i = nums.size() - 2; i >= n / 3; i -= 2) {
            // cout << i << endl;
            ans += nums[i];
        }
        return ans;
    }
};