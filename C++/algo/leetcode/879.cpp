// 879. Profitable Schemes [H]
// LeetCode profitable-schemes

int MOD = 1e9 + 7;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size();
        vector memo(
            len, 
            vector(n + 1,
                vector(
                    minProfit + 1,
                    -1LL
                )
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int g, int target) {
            if(g < 0) return 0LL; 
            if(i >= len) return target == 0 ? 1LL : 0LL;         
            if(memo[i][g][target] != -1) return memo[i][g][target];
            int p1 = dfs(i + 1, g, target);
            return memo[i][g][target] = (
                dfs(i + 1, g - group[i], max(0, target - profit[i])) + 
                dfs(i + 1, g, target)
            ) % MOD;
        };
        return dfs(0, n, minProfit);
    }
};