// 3523. Make Array Non-decreasing [M]
// LeetCode make-array-non-decreasing

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> ans;        
        for(int num : nums) {
            int curMax = num;
            while(!ans.empty() && ans.back() > curMax) {
                curMax = max(curMax, ans.back());
                ans.pop_back();
            }
            ans.push_back(curMax);
        }
        
        return ans.size();
    }
};