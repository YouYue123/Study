// 325. Maximum Size Subarray Sum Equals k [M]
// LeetCode maximum-size-subarray-sum-equals-k

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            sum += num;
            int target = sum - k;
            if(dict.contains(target)) {
                ans = max(ans, i - dict[target]);
            }
            if(!dict.contains(sum)) dict[sum] = i;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};