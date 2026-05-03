#include <bits/stdc++.h>
using namespace std;

// 818. Race Car [H]
// LeetCode race-car

class Solution {
public:
    int racecar(int target) {
        vector memo(target + 1, -1);
        auto dfs = [&] (this auto&& dfs, int i) -> int {
            if(i == 0) return 0;
            if(memo[i] != -1) return memo[i];
            int n = 0;
            while((1 << n) - 1 < i) n += 1;
            int curDist = (1 << n) - 1;
            if(curDist == i) return memo[i] = n;
            int ans = n + 1 + dfs(curDist - i);
            for(int k = 0; k < n - 1; k ++) {
                int dist = (1 << (n - 1)) - (1 << k);
                ans = min(
                    ans,
                    n - 1 + 1 + k + 1 + dfs(i - dist)
                );
            }
            return memo[i] = ans;
        };
        return dfs(target);
    }
};