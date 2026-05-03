// 1130. Minimum Cost Tree From Leaf Values [M]
// LeetCode minimum-cost-tree-from-leaf-values

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector maxVal(n, vector(n, 0));
        for(int i = 0; i < n; i ++) {
            maxVal[i][i] = arr[i];
            for(int j = i + 1; j < n; j ++) {
                maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
            }
        }
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            for(int k = i; k < j; k ++) {
                ans = min(
                    ans,
                    maxVal[i][k] * maxVal[k + 1][j] + dfs(i, k) + dfs(k + 1, j)
                );
            }
            return memo[i][j] = ans;
        };

        return dfs(0, n - 1);
    }
};