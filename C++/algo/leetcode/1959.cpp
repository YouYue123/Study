#include <bits/stdc++.h>
using namespace std;

// 1959. Minimum Total Space Wasted With K Resizing Operations [M]
// LeetCode minimum-total-space-wasted-with-k-resizing-operations

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = INT_MIN;
        vector preSum(n + 1, 0);
        for(int i = 0; i < n; i ++) preSum[i + 1] = preSum[i] + nums[i];
        
        vector memo(n, vector(n + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt > k + 1) return INT_MAX / 2;
            if(i == n) return 0;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int mx = INT_MIN;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                mx = max(mx, nums[j]);
                int cost = mx * (j - i + 1) - (preSum[j + 1] - preSum[i]);
                ans = min(ans, dfs(j + 1, cnt + 1) + cost);
            }
            return memo[i][cnt] = ans;
        };
        
        return dfs(0, 0);
    }
};