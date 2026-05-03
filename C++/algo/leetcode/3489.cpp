// 3489. Zero Array Transformation IV [M]
// LeetCode zero-array-transformation-iv

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector dict(
            n,
            vector<pair<int, int>>()
        );
        for(int k = 0; k < queries.size(); k ++) {
            auto& q = queries[k];
            int l = q[0], r = q[1], val = q[2];
            for(int i = l; i <= r; i ++) {
                dict[i].push_back({val, k});
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            auto& pairs = dict[i];
            vector memo(
                pairs.size(),
                vector(
                    nums[i] + 1,
                    -1
                )
            );
            auto dfs = [&] (this auto&& dfs, int i, int cur) {
                if(cur == 0) return pairs[i - 1].second + 1;
                if(i >= pairs.size() || cur < 0) return INT_MAX;
                if(memo[i][cur] != -1) return memo[i][cur];
                auto& p = pairs[i];
                return memo[i][cur] = min(
                    dfs(i + 1, cur - pairs[i].first),
                    dfs(i + 1, cur)
                );
            };
            if(nums[i] != 0) ans = max(ans, dfs(0, nums[i]));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};