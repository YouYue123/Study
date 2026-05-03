// 560. Subarray Sum Equals K [M]
// LeetCode subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sum_now - prev_pre_sum = k
        // need to know the cnt of prev_pre_sum
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int num : nums) {
            sum += num;
            int target = sum - k;
            ans += cnt[target];
            cnt[sum] += 1;
        }
        return ans;
    }
};