// 2403. Minimum Time to Kill All Monsters [H]
// LeetCode minimum-time-to-kill-all-monsters

long long constexpr INF = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n = power.size();
        int full = (1 << n) - 1;
        vector memo(1 << n, -1LL);
        auto dfs = [&] (this auto& dfs, int state) -> long long {
            if(full == state) return 0;
            if(memo[state] != -1) return memo[state];
            long long ans = INF;
            int gain = __builtin_popcount(state) + 1;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                long long day = power[i] / gain + (power[i] % gain == 0 ? 0 : 1);
                ans = min(
                    ans,
                    dfs(state | (1 << i)) + day
                );
            }
            return memo[state] = ans;
        };

        return dfs(0);
    }
};