// 1099. Two Sum Less Than K [E]
// LeetCode two-sum-less-than-k

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                ans = max(ans, sum);
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};