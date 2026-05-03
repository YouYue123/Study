#include <bits/stdc++.h>
using namespace std;

// 3538. Merge Operations for Minimum Travel Time [H]
// LeetCode merge-operations-for-minimum-travel-time

class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> tPreSum(n + 1, 0);
        for(int i = 0; i < n; i ++) tPreSum[i + 1] = tPreSum[i] + time[i];
        vector memo(
            n, 
            vector(
                n,
                vector(k + 1, -1)
            )
        );
        auto dfs = [&] (this auto&& dfs, int i, int j, int leftK) {
            if(leftK < 0) return INT_MAX / 2;
            if(j == n - 1) return leftK == 0 ? 0 : INT_MAX / 2;
            if(memo[i][j][leftK] != -1) return memo[i][j][leftK];
            int ans = INT_MAX / 2;
            int mergeCnt = -1;
            for(int k = j + 1; k < n; k ++) {
                int cost = (position[k] - position[j]) * (tPreSum[j + 1] - tPreSum[i]);
                mergeCnt += 1;
                ans = min(ans, dfs(j + 1, k, leftK - mergeCnt) + cost);
            }
            return memo[i][j][leftK] = ans;
        };

        return dfs(0, 0, k);
    }
};