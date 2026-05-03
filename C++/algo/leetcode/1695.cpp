// 1695. Maximum Erasure Value [M]
// LeetCode maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> dict;
        int left = 0, right = 0;
        int sum = 0;
        int ans = 0;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            sum += nums[right];
            while(dict[nums[right]] > 1) {
                dict[nums[left]] -= 1;
                sum -= nums[left];
                left += 1;
            }
            ans = max(ans, sum);
            right += 1;
        }
        return ans;
    }
};