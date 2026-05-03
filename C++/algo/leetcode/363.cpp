// 363. Max Sum of Rectangle No Larger Than K [H]
// LeetCode max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int calc(vector<int>& nums, int k) {
        int ans = INT_MIN;
        vector<int> presum(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i ++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        for(int i = 0; i < nums.size(); i ++) {
            for(int j = 0; j <= i; j ++) {
                // [j, i]
                int curSum = presum[i + 1] - presum[j];
                if(curSum <= k) {
                    ans = max(ans, curSum);
                }
            }
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        for(int i = 0 ; i < m; i ++) {
            vector<int> colSum(n);
            for(int i2 = i; i2 < m; i2 ++) {
                for(int j = 0; j < n; j ++) {
                    colSum[j] += matrix[i2][j];
                }
                ans = max(ans, calc(colSum, k));
            }
        }
        return ans;
    }
};