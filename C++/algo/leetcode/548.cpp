// 548. Split Array with Equal Sum [H]
// LeetCode split-array-with-equal-sum

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 7) return false;
        vector<int> presum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        for(int j = 3; j < nums.size() - 3; j ++) {
            unordered_set<int> dict;
            for(int i = 1; i < j - 1; i ++) {
                // （0, i - 1) == (i + 1, j - 1)
                if(presum[i] == presum[j] - presum[i + 1]) dict.insert(presum[i]);
            }
            for(int k = j + 2; k < nums.size() - 1; k ++) {
                // (j + 1, k - 1)
                int target = presum[k] - presum[j + 1];
                // (k + 1, nums.size() - 1)
                if(presum[n] - presum[k + 1] ==target && dict.contains(target)) {
                    return true;
                }
            }
        }
        return false;
    }
};