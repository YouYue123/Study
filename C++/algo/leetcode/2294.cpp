// 2294. Partition Array Such That Maximum Difference Is K [M]
// LeetCode partition-array-such-that-maximum-difference-is-k

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // [3, 6, 1, 2, 5]
        // k = 2
        sort(nums.begin(), nums.end());
        int curMin = INT_MAX;
        int curMax = INT_MIN;
        int ans = 1;
        for(int num : nums) {
            curMin = min(curMin, num);
            curMax = max(curMax, num);
            if(curMax - curMin > k) {
                curMax = num;
                curMin = num;
                ans += 1;
            }
        } 
        return ans;
    }
};