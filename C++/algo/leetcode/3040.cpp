// 3040. Maximum Number of Operations With the Same Score II [M]
// LeetCode maximum-number-of-operations-with-the-same-score-ii

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j, int prev) {
            if(j - i + 1 < 2) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = max({
                prev == nums[i] + nums[i + 1] ? dfs(i + 2, j, nums[i] + nums[i + 1]) + 1 : 0,
                prev == nums[j] + nums[j - 1] ? dfs(i, j - 2, nums[j] + nums[j - 1]) + 1 : 0,
                prev ==  nums[i] + nums[j] ? dfs(i + 1, j - 1, nums[i] + nums[j]) + 1 : 0
            });
            return memo[i][j] = ans;
        };
        int ans = 0;
        int a = nums[0] + nums[1];  
        ans = max(ans, dfs(2, n - 1, a) + 1);
        for(auto& item : memo) item.clear();
        int b = nums[0] + nums[n - 1];
        ans = max(ans, dfs(1, n - 2, b) + 1);
        for(auto& item : memo) item.clear();
        int c = nums[n - 1] + nums[n - 2]; 
        ans = max(ans, dfs(0, n - 3, c) + 1);
        return ans;
    }
};