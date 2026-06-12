#include <bits/stdc++.h>
using namespace std;

// 1696. Jump Game VI [M]
// LeetCode jump-game-vi

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector dp(n, -INF);
        dp[0] = nums[0];
        deque<int> q;
        for(int i = 0; i < n; i ++) {
            dp[i] = (q.empty() ? 0 : dp[q.front()]) + nums[i];
            while(!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
            if(i - q.front() == k) q.pop_front();
            // for(int j = max(0, i - k); j < i; j ++) {
            //     dp[i] = max(
            //         dp[i],
            //         dp[j] + nums[i]
            //     );
            // }
        }
        return dp[n - 1];
    }
};
