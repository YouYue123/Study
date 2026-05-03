// 2602. Minimum Operations to Make All Array Elements Equal [M]
// LeetCode minimum-operations-to-make-all-array-elements-equal

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> preSum(n + 1);
        for(int i = 0; i < n; i ++) preSum[i + 1] = preSum[i] + nums[i];
        for(int x: queries) {
            long long left = 0, right = n;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(nums[mid] >= x) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            long long pre = (left * x) - preSum[left];
            long post = (preSum[n] - preSum[left]) - (n - left) * x;
            ans.push_back(pre + post); 
        }
        return ans;
    }
};