#include <bits/stdc++.h>
using namespace std;

// 1425. Constrained Subsequence Sum [H]
// LeetCode constrained-subsequence-sum

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector dp(n, 0);
        deque<long long> q;
        int ans = -INF;
        for(int i = 0; i < n; i ++) {
            dp[i] = q.empty() ? nums[i] : max(dp[q.front()] + nums[i], nums[i]);
            while(!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if(i - q.front() == k) {
                q.pop_front();
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};