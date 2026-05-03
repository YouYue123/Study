// 1365. How Many Numbers Are Smaller Than the Current Number [E]
// LeetCode how-many-numbers-are-smaller-than-the-current-number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums) freq[num] += 1;
        vector<int> presum(102, 0);
        for(int i = 0; i < freq.size(); i ++) {
            presum[i + 1] = presum[i] + freq[i];
        }
        vector<int> ans;
        for(int num : nums) {
            ans.push_back(presum[num] - presum[0]);
        }
        return ans;
    }
};