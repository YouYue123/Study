// 276. Paint Fence [M]
// LeetCode paint-fence

class Solution {
public:
    int numWays(int n, int k) {
        vector memo(n, vector(4, -1));
        auto dfs = [&] (this auto&& dfs, int i, int state) {
            if(i == n) return 1;
            if(memo[i][state] != -1) return memo[i][state];
            int ans = 0;
            if(state == 0) {
                ans += dfs(i + 1, 1);
                ans += (k - 1) * dfs(i + 1, 0);
            } else if (state == 1) {
                ans += (k - 1) * dfs(i + 1, 0);
            }
            return memo[i][state] = ans;
        };
        return k * dfs(1, 0);
    }
};