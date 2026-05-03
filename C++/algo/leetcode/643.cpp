// 643. Maximum Average Subarray I [E]
// LeetCode maximum-average-subarray-i

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = -INF;
        int left = 0;
        long long sum = 0;
        for(int right = 0; right < n; right ++) {
            sum += nums[right];
            if(right - left + 1 > k) {
                sum -= nums[left];
                left += 1;
            }
            if(right - left + 1 == k) {
                ans = max(
                    ans,
                    1.0 * sum / k
                );
            }
        }
        return ans;
    }
};