// 1458. Max Dot Product of Two Subsequences [H]
// LeetCode max-dot-product-of-two-subsequences

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector memo(m, vector(n, vector(2, INF)));
        auto dfs = [&] (this auto&& dfs, int i, int j, bool empty) {
            if(i == m || j == n) return empty ? -INF : 0;
            if(memo[i][j][empty] !=  INF) return memo[i][j][empty];
            int ans = nums1[i] * nums2[j] + dfs(i + 1, j + 1, false);
            ans = max(ans, dfs(i + 1, j, empty));
            ans = max(ans, dfs(i, j + 1, empty));
            return memo[i][j][empty] = ans;
        };
        return dfs(0, 0, true);
    }
};