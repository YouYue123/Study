#include <bits/stdc++.h>
using namespace std;

// 3473. Sum of K Subarrays With Length at Least M [M]
// LeetCode sum-of-k-subarrays-with-length-at-least-m

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for(int i = 0; i < n; i ++) preSum[i + 1] = preSum[i] + nums[i];

        vector f(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= k; i++) {
            f[i][i * m - 1] = INT_MIN;
            int mx = INT_MIN;
            for (int j = i * m; j <= n; j++) {
                mx = max(mx, f[i - 1][j - m] - preSum[j - m]);
                f[i][j] = max(f[i][j - 1], mx + preSum[j]); 
            }
        }
        return f[k][n];
    }
};