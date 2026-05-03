// 2247. Maximum Cost of Trip With K Highways [H]
// LeetCode maximum-cost-of-trip-with-k-highways

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        vector cost(n, vector(n, INF));
        for(auto& h : highways) {
            int c1 = h[0], c2 = h[1], t = h[2];
            cost[c1][c2] = t;
            cost[c2][c1] = t;
        }
        vector memo(1 << n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int state, int prev) {
            int cnt = __builtin_popcount(state) - 1;
            if(cnt == k) return 0;
            if(memo[state][prev] != -1) return memo[state][prev];
            int ans = -INF;
            for(int i = 0; i < n; i ++) {
                if(state & (1 << i)) continue;
                if(cost[prev][i] != INF) {
                    ans = max(
                        ans,
                        dfs(state | (1 << i), i) + cost[prev][i]
                    );
                }
            }
            return memo[state][prev] = ans;
        };
        int ans = -1;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, dfs(1 << i, i));
        }
        return ans;
    }
};