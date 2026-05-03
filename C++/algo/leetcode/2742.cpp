#include <bits/stdc++.h>
using namespace std;

// 2742. Painting the Walls [H]
// LeetCode painting-the-walls

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector memo(
            n,
            vector(
                1001,
                -1
            )
        );
        auto dfs = [&](this auto&& dfs, int i, int t) {
            // cout << i << " " << t << endl;
            if(i >= n) return t < 0 ? INT_MAX / 2 : 0;
            if(t >= 500) return 0;
            if(memo[i][t + 500] != -1) return memo[i][t + 500];
            int paid = dfs(i + 1, t + time[i]) + cost[i];
            int free = dfs(i + 1, t - 1);
            return memo[i][t + 500] = min(paid, free);
        };
        return dfs(0, 0);
    }
};