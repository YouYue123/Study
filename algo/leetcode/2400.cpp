#include <bits/stdc++.h>
using namespace std;

// 2400. Number of Ways to Reach a Position After Exactly k Steps [M]
// LeetCode number-of-ways-to-reach-a-position-after-exactly-k-steps

int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        
        vector memo(3001, vector(k + 1, -1LL));
        auto dfs = [&] (this auto&& dfs, int pos, int remainStep) {
            if(remainStep == 0) return pos == endPos ? 1LL : 0LL;
            if(memo[pos + 1000][remainStep] != -1) return memo[pos + 1000][remainStep];
            long long ans = 0;
            ans = (ans + dfs(pos - 1, remainStep - 1)) % MOD;
            ans = (ans + dfs(pos + 1, remainStep - 1)) % MOD;
            return memo[pos + 1000][remainStep] = ans;
        };

        return dfs(startPos, k);
    }
};