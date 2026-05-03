// 1547. Minimum Cost to Cut a Stick [H]
// LeetCode minimum-cost-to-cut-a-stick

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector memo(m + 1, vector(m + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i + 1 == j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            // cout << i << " " << j << endl;
            int ans = INF;
            for(int k = i + 1; k < j; k ++) {
                ans = min(
                    ans,
                    dfs(i, k) + dfs(k, j) + (cuts[j] - cuts[i])
                );
            }
            return memo[i][j] = ans;
        };
        return dfs(0, m - 1);
    }
};