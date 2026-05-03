// 3202. Find the Maximum Length of Valid Subsequence II [M]
// LeetCode find-the-maximum-length-of-valid-subsequence-ii

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector dp(k, vector(k, 0));
        int ans = 0;
        for(int x : nums) {
            x %= k;
            for(int y = 0; y < k; y ++) {
                dp[x][y] = dp[y][x] + 1;
                ans = max(ans, dp[x][y]);
            }
        }
        return ans;
    }
};