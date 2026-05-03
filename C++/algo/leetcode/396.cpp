// 396. Rotate Function [M]
// LeetCode rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0, cur = 0;
        for(int i = 0; i < n; i ++) {
            sum += nums[i];
            cur += i * nums[i];
        }
        int right = n - 1;
        ans = cur;
        while(right > 0) {
            cur += sum - n * nums[right];
            ans = max(ans, cur);
            right -= 1;
        }
        return ans;
    }
};