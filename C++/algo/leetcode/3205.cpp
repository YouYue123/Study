// 3205. Maximum Array Hopping Score I [M]
// LeetCode maximum-array-hopping-score-i

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int memo[n];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n - 1) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = 0;
            for(int j = i + 1; j < n; j ++) {
                ans = max(ans, dfs(j) + (j - i) * nums[j]);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};