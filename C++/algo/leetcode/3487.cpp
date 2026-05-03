// 3487. Maximum Unique Subarray Sum After Deletion [E]
// LeetCode maximum-unique-subarray-sum-after-deletion

class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        unordered_set<int> dict;
        int ans = 0;
        for(int num : nums) {
            if(!dict.contains(num)) {
                dict.insert(num);
                if(num > 0) ans += num;
            }
        }
        return ans == 0 ? nums.back() : ans;
    }
};