#include <bits/stdc++.h>
using namespace std;

// 375. Guess Number Higher or Lower II [M]
// LeetCode guess-number-higher-or-lower-ii

int constexpr INF = 0x3f3f3f3f3f;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector memo(n + 1, vector(n + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i >= j) return 0;
            if(memo[i][j] != -1) return memo[i][j];
            int ans = INF;
            for(int k = (i + j) / 2; k < j; k ++) {
                ans = min(
                    ans,
                    k + max(dfs(i, k - 1), dfs(k + 1, j))
                );
            }
            return memo[i][j] =  ans;
        };

        return dfs(1, n);
    }
};