#include <bits/stdc++.h>
using namespace std;

// 279. Perfect Squares [M]
// LeetCode perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector memo(
            sqrt(n) + 1,
            vector(
                n + 1,
                -1
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int target) {
            if(target < 0 || i < 1) return INT_MAX / 2;
            if(target == 0) return 0;
            // cout << i << " " << target << endl;
            if(memo[i][target] != -1) return memo[i][target];
            return memo[i][target] = min(
                dfs(i, target - i * i) + 1,
                dfs(i - 1, target)
            );
        };
        return dfs(sqrt(n), n);
    }
};