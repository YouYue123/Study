// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons [H]
// LeetCode build-array-where-you-can-find-the-maximum-exactly-k-comparisons

int MOD = 1e9 + 7;
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector memo(n, vector(m + 1, vector(k + 1, -1)));
        auto dfs = [&] (this auto&& dfs, int i, int curMax, int cost) {
            if(cost > k) return 0;
            if(i == n) return cost == k ? 1 : 0;
            if(memo[i][curMax][cost] != -1) return memo[i][curMax][cost];
            int ans = 0;
            for(int num = 1; num <= m; num ++) {
                ans = (ans + dfs(i + 1, max(curMax, num), cost + (num > curMax ? 1 : 0))) % MOD;
            }
            return memo[i][curMax][cost] = ans;
        };
        return dfs(0, 0, 0);
    }
};