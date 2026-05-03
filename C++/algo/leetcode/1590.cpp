// 1590. Make Sum Divisible by P [M]
// LeetCode make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int num : nums) sum += num;
        int target = sum % p;
        if(target == 0) return 0;
        long long presum = 0;
        unordered_map<int, int> dict;
        dict[presum] = -1;
        // presum[i] - presum[j] = target (mod p)
        // presum[i] - target = presum[j] (mod p)
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            presum += nums[i];
            int t = (presum % p - target + p) % p;
            if(dict.contains(t)) {
                ans = min(
                    ans,
                    i - dict[t]
                );
            }
            dict[presum % p] = i;  
        }
        return ans == INT_MAX || ans == nums.size() ? -1 : ans;
    }
};