// 2302. Count Subarrays With Score Less Than K [H]
// LeetCode count-subarrays-with-score-less-than-k

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int left = 0, right = 0;
        while(right < nums.size()) {
            sum += nums[right];
            while(sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left += 1;
            }
            ans += right - left + 1;
            right += 1;
        }
        return ans;
    }
};