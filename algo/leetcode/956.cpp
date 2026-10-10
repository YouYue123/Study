#include <bits/stdc++.h>
using namespace std;

// 956. Tallest Billboard [H]
// LeetCode tallest-billboard

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        for(int r : rods) sum += r;
        vector memo(
            n,
            vector(
                10001,
                -1
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int s) {
            if(i == n) {
                return s == 5000 ? 0 : INT_MIN;
            }
            if(memo[i][s] != -1) return memo[i][s];
            return memo[i][s] = max({
                dfs(i + 1, s - rods[i]),
                rods[i] + dfs(i + 1, s + rods[i]),
                dfs(i + 1, s),
            });
        };
        return dfs(0, 5000);
    }
};