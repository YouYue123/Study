#include <bits/stdc++.h>
using namespace std;

// 3647. Maximum Weight in Two Bags [M]
// LeetCode maximum-weight-in-two-bags

class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        sort(weights.begin(), weights.end());
        int n = weights.size();
        vector memo(
            n,
            vector(
                w1 + 1,
                vector(w2 + 1, -1)
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int w1, int w2) {
            if(w1 < 0 || w2 < 0) return INT_MIN;
            if(i == n) return 0;
            if(memo[i][w1][w2] != -1) return memo[i][w1][w2];
            return memo[i][w1][w2] = max({
                dfs(i + 1, w1, w2),
                dfs(i + 1, w1 - weights[i], w2) + weights[i],
                dfs(i + 1, w1, w2 - weights[i]) + weights[i],
            });
        };
        return dfs(0, w1, w2);
    }
};