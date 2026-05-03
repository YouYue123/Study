#include <bits/stdc++.h>
using namespace std;

// 3290. Maximum Multiplication Score [M]
// LeetCode maximum-multiplication-score

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector memo(
            4,
            vector(n, LLONG_MIN)
        );
        auto dfs = [&](this auto&& dfs, int aIdx, int bIdx) -> long long{
            if(aIdx >= 4) return 0;
            if(bIdx >= n) return LLONG_MIN / 2;
            if(memo[aIdx][bIdx] != LLONG_MIN) return memo[aIdx][bIdx];
            return memo[aIdx][bIdx] = max(
                dfs(aIdx + 1, bIdx + 1) + (long long)a[aIdx] * b[bIdx],
                dfs(aIdx, bIdx + 1)
            );
        };
        return dfs(0, 0);
    }
};