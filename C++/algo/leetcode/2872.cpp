// 2872. Maximum Number of K-Divisible Components [H]
// LeetCode maximum-number-of-k-divisible-components

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, int x, int fa) -> long long {
            long long sum = values[x];
            for(int nx : g[x]) {
                if(nx != fa) {
                    sum += dfs(nx, x);
                }
            }
            if(sum % k == 0) ans += 1;
            return sum;
        };
        dfs(0, -1);
        return ans;
    }
};