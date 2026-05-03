// 1911. Maximum Alternating Subsequence Sum [M]
// LeetCode maximum-alternating-subsequence-sum

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector memo(
            n,
            vector(2, -1LL)
        );
        auto dfs = [&](this auto& dfs, int i, int state) -> long long{
            if(i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = dfs(i + 1, state);
            if(state == 0) {
                ans = max(ans, dfs(i + 1, 1) + nums[i]);
            } else {
                ans = max(ans, dfs(i + 1, 0) - nums[i]);
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};