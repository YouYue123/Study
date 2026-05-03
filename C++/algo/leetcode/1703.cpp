// 1703. Minimum Adjacent Swaps for K Consecutive Ones [H]
// LeetCode minimum-adjacent-swaps-for-k-consecutive-ones

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> p;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] == 1) p.push_back(i - p.size());
        }
        int m = p.size();
        vector<int> presum(m + 1, 0);
        for(int i = 1; i <= m; i ++) {
            presum[i] = presum[i - 1] + p[i - 1];
        }
        int ans = INT_MAX;
        for(int i = 0; i <= m - k; i ++) {
            int medianIdx = i + k / 2;
            int medianVal = p[medianIdx];
            int pre =  medianVal * (k / 2) - (presum[medianIdx] - presum[i]);
            int rightCnt = k / 2 + 1;
            int post = (presum[i + k] - presum[medianIdx + 1]) - medianVal * (k - 1 - k / 2);
            ans = min(ans, pre + post);
        }
        return ans;
    }
};