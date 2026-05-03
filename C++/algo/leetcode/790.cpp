#include <bits/stdc++.h>
using namespace std;

// 790. Domino and Tromino Tiling [M]
// LeetCode domino-and-tromino-tiling

int MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        vector memo(n, vector(2, -1LL));
        auto dfs = [&] (this auto&& dfs, int i, bool is_special) -> long long {
            if(i > n) return 0;
            if(i == n) return is_special ? 0 : 1;
            if(memo[i][is_special] != -1LL) return memo[i][is_special];
            int ans = 0;
            if (is_special) { // staggered: H to close or L to extend (+1)
                ans = (dfs(i + 1, false) + dfs(i + 1, true)) % MOD;
            } else { // aligned: V (+1), HH (+2), L×2 (+2)
                ans = (dfs(i + 1, false) + dfs(i + 2, false) + 2 * dfs(i + 2, true) % MOD) % MOD;
            }
            return memo[i][is_special] = ans;
        };

        return dfs(0, false);
    }
};