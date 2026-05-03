#include <bits/stdc++.h>
using namespace std;

// 2463. Minimum Total Distance Traveled [H]
// LeetCode minimum-total-distance-traveled

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size(), m = factory.size();
        vector memo(n, vector(m, -1LL));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if(i == n) return 0LL;
            if(j == m) return LLONG_MAX / 2;
            if(memo[i][j] != -1) return memo[i][j];
            int pos = factory[j][0], limit = factory[j][1];
            long long ans = dfs(i, j + 1);
            long long sum = 0;
            for(int k = 1; k <= limit && i + k - 1 < n; k ++) {
                sum += abs(pos - robot[i + k - 1]);
                ans = min(ans, dfs(i + k, j + 1) + sum);
            }
            return memo[i][j] = ans;
        };

        return dfs(0, 0);
    }
};