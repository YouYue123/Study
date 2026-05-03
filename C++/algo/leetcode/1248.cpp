// 1248. Count Number of Nice Subarrays [M]
// LeetCode count-number-of-nice-subarrays

class Solution {
public:
    int f(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;
        int ans = 0;
        while(right < nums.size()) {
            count += nums[right] % 2 == 1;
            while(count >= k) {
                count -= nums[left] % 2 == 1;
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k + 1);
    }
};