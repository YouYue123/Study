#include <bits/stdc++.h>
using namespace std;

// 416. Partition Equal Subset Sum [M]
// LeetCode partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        int n = nums.size();
        if(totalSum % 2 == 1) return false;
        int target = totalSum / 2;
        vector memo(
            n,
            vector(200 * 100 + 1, -1)
        );
        auto dfs = [&](this auto&& dfs, int i, int target) {
            if(target < 0) return false;
            if(target == 0) return true;
            if(i == n - 1) return false;
            if(memo[i][target] != -1) return memo[i][target] == 1;
            bool ans = dfs(i + 1, target - nums[i]) || dfs(i + 1, target);
            if(ans) memo[i][target] = 1;
            else memo[i][target] = 0;
            return ans;
        };
        return dfs(0, target);
    }
};