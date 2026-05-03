// 2009. Minimum Number of Operations to Make Array Continuous [H]
// LeetCode minimum-number-of-operations-to-make-array-continuous

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for(int num : unique) newNums.push_back(num);        
        int left = 0, right = 0;
        int ans = n;
        while(left < newNums.size()) {
            while(right < newNums.size() && newNums[right] - newNums[left] < n) {
                right += 1;
            }
            int count = right - left;
            ans = min(ans, n - count);
            left += 1;
        }
        return ans;
    }
};