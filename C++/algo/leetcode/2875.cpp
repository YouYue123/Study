// 2875. Minimum Size Subarray in Infinite Array [M]
// LeetCode minimum-size-subarray-in-infinite-array

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(begin(nums), end(nums), 0LL);
        int n = nums.size();
        if (total == 0) return -1;
        int k = target / total;
        long subTarget = target % total;
        int ans = INT_MAX;
        int left = 0, right = 0;
        long sum = 0;
        while(left < n) {
            sum += nums[right % n];
            while(left < n && sum >= subTarget) {
                if(sum == subTarget) ans = min(ans, right - left + 1);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        if (subTarget == 0) return k * n;
        return ans == INT_MAX ? -1 : k * n + ans;
    }
};