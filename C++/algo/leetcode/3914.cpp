// 3914. Minimum Operations to Make Array Non Decreasing [M]
// LeetCode minimum-operations-to-make-array-non-decreasing

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        int cur_min = nums[n - 1];
        long long ans = 0;
        for(int i = n - 2; i >= 0; i --) {
            // ans = max(ans, nums[i] - cur_min);
            if(i > 0 && nums[i - 1] < nums[i]) {
                ans += max(0, nums[i] - cur_min);
                cur_min = nums[i - 1];
            } else if (i == 0) {
                ans += max(0, nums[i] - cur_min);
            } else {
                cur_min = min(cur_min, nums[i]);
            }
        }
        return ans;
    }
};