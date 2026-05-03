// 219. Contains Duplicate II [E]
// LeetCode contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> dict;
        for(int i = 0; i < n; i ++) {
            if(dict.contains(nums[i])) {
                if(i - dict[nums[i]] <= k) return true;
            }
            dict[nums[i]] = i;
        }
        return false;
    }
};