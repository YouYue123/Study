// 3727. Maximum Alternating Sum of Squares [M]
// LeetCode maximum-alternating-sum-of-squares

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return (long long) a * a < (long long)b * b;
        });
        int left = 0, right = nums.size() - 1;
        long long ans = 0;
        while(left < right) {
            // cout << nums[left] << " " << nums[right] << endl;
            ans -=  nums[left] * nums[left];
            ans += nums[right] * nums[right];
            left += 1;
            right -= 1;
        }
        if(left == right) ans += nums[left] * nums[left];
        return ans;
    }
};