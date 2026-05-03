// 3289. The Two Sneaky Numbers of Digitville [E]
// LeetCode the-two-sneaky-numbers-of-digitville

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> dict;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            dict[num] += 1;
            if(dict[num] > 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};