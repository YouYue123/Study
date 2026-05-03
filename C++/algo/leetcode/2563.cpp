// 2563. Count the Number of Fair Pairs [M]
// LeetCode count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++) {
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto it2 = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            ans += it2 - it1;
        }
        return ans;
    }
};