// 213. House Robber II [M]
// LeetCode house-robber-ii

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(vector<int>(n + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int end) -> int {
            if(i >= end) return 0;
            if(memo[i] != -1) return memo[i];
            return memo[i] = max(
                dfs(i + 2, end) + nums[i],
                dfs(i + 1, end)
            );
        };
        int rob = dfs(2, n - 1) + nums[0];
        memo.assign(n + 1, -1);
        int skip = dfs(1, n);
        return max(
           rob, skip
        );
    }
};