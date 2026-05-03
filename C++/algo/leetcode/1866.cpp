#include <bits/stdc++.h>
using namespace std;

// 1866. Number of Ways to Rearrange Sticks With K Sticks Visible [H]
// LeetCode number-of-ways-to-rearrange-sticks-with-k-sticks-visible

int MOD = 1e9 + 7;
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector memo(n, vector(k + 1, -1LL));
        auto dfs = [&] (this auto&& dfs, int i, int vis_cnt) -> long long {
            if(vis_cnt > k) return 0LL;
            if(i == n) return vis_cnt == k ? 1LL : 0LL;
            if(memo[i][vis_cnt] != -1) return memo[i][vis_cnt];
            long long ans = dfs(i + 1, vis_cnt + 1);
            ans = (ans + 1LL * i * dfs(i + 1, vis_cnt) % MOD) % MOD;
            return memo[i][vis_cnt] = ans;
        };
        return dfs(0, 0);
    }
};