// 2389. Longest Subsequence With Limited Sum [E]
// LeetCode longest-subsequence-with-limited-sum

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> preSum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        vector<int> ans;
        for(int q : queries) {
            int left = 0, right = preSum.size();
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(preSum[mid] > q) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(left != 0) {
                ans.push_back(left - 1);
            }
        }
        return ans;
    }
};