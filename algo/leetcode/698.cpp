#include <bits/stdc++.h>
using namespace std;

// 698. Partition to K Equal Sum Subsets [M]
// LeetCode partition-to-k-equal-sum-subsets

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % k != 0) return false;
        int target = sum / k;
        vector memo((1 << n), -1);
        auto dfs = [&] (this auto&& dfs, int mask, int cur_sum) -> bool {
            if(mask == 0) return true;
            if(memo[mask] != -1) return memo[mask] == 1;
            for(int i = 0; i < n; i ++) {
                int curMask = (1 << i);
                if(mask & curMask) {
                    if(cur_sum + nums[i] <= target) {
                        int nxt_sum = (cur_sum + nums[i]) % target;
                        if(dfs(mask ^ curMask, nxt_sum)) {
                            return memo[mask] = 1;
                        }
                    }
                }
            }
            return memo[mask] = 0;
        };
        return dfs((1 << n) - 1, 0);
    }
};