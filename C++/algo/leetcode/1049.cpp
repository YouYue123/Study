// 1049. Last Stone Weight II [M]
// LeetCode last-stone-weight-ii

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector memo(n, vector(6001, -1));
        auto dfs = [&] (this auto&& dfs, int i, int prev) {
            if(i == n) return prev < 0 ? INT_MAX : prev;
            if(memo[i][prev + 3000] != -1) return memo[i][prev + 3000];
            return memo[i][prev + 3000] = min(
                dfs(i + 1, prev - stones[i]),
                dfs(i + 1, prev + stones[i])
            );
        };
        return dfs(0, 0);
    }
};