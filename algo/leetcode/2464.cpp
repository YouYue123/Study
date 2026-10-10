#include <bits/stdc++.h>
using namespace std;

// 2464. Minimum Subarrays in a Valid Split [M]
// LeetCode minimum-subarrays-in-a-valid-split

class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        auto gcd = [&] (int a, int b) {
            while(b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        };
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                if(gcd(nums[i], nums[j]) > 1) {
                    int remain = dfs(j + 1);
                    if(remain != INT_MAX) ans = min(ans, remain + 1);
                }
            }
            return memo[i] = ans;
        };
        return dfs(0) == INT_MAX ? -1 : dfs(0);
    }
};