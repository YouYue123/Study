// 1. Two Sum [E]
// LeetCode two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dict;
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            // num + prev_num = target
            int prev_num = target - num;
            if(dict.contains(prev_num)) {
                return { dict[prev_num], i };
            }
            dict[num] = i;
        }
        return {-1, -1 };
    }
};