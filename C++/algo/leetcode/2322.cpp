// 2322. Minimum Score After Removals on a Tree [H]
// LeetCode minimum-score-after-removals-on-a-tree

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for(auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> xr(n), in(n), out(n);
        int clock = 0;
        auto dfs = [&] (this auto&& dfs, int x, int fa)  -> void {
            clock += 1;
            in[x] = clock;
            xr[x] = nums[x];
            for(int y : g[x]) {
                if (y != fa) {
                    dfs(y, x);
                    xr[x] ^= xr[y];
                }
            }
            out[x] = clock;
        };
        dfs(0, -1);
        auto is_ancestor = [&] (int x, int y) {
            return in[x] < in[y] && in[y] <= out[x];
        };
        int ans = INT_MAX;
        for(int x = 2; x < n; x ++) {
            for(int y = 1; y < x; y ++) {
                 int a, b, c;
                if (is_ancestor(x, y)) { 
                    a = xr[y], b = xr[x] ^ a, c = xr[0] ^ xr[x];
                } else if (is_ancestor(y, x)) { 
                    a = xr[x], b = xr[y] ^ a, c = xr[0] ^ xr[y];
                } else { 
                    a = xr[x], b = xr[y], c = xr[0] ^ a ^ b;
                }
                ans = min(ans, max({a, b, c}) - min({a, b, c}));
                if (ans == 0) { // 不可能变小
                    return 0; // 提前返回
                }
            }
        }
        return ans;
    }
};