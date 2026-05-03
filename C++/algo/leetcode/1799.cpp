// 1799. Maximize Score After N Operations [H]
// LeetCode maximize-score-after-n-operations

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int full = (1 << n) - 1;
        // cout << full << endl;
        vector memo(1 << n, -1);
        auto dfs = [&] (this auto&& dfs, int state) {
            if(state == full) return 0;
            if(memo[state] != -1) return memo[state];
            int ans = 0;
            int cnt = __builtin_popcount(state) / 2 + 1;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                for (int j = i + 1; j < n; j ++) {
                    if(state & (1 << j)) continue;
                    ans = max(
                        ans,
                        dfs(state | (1 << i) | (1 << j)) + cnt * gcd(nums[i], nums[j])
                    );
                }
            }
            return memo[state] = ans;
        };

        return dfs(0);
    }
};