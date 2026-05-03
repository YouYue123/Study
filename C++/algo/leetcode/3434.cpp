#include <bits/stdc++.h>
using namespace std;

// 3434. Maximum Frequency After Subarray Operation [M]
// LeetCode maximum-frequency-after-subarray-operation

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int memo[n][3];
        for(int t = 1; t <= 50; t ++) {
            memset(memo, -1, sizeof(memo));
            auto dfs = [&] (this auto&& dfs, int i, int state) {
                if(i == n) return 0;
                if(memo[i][state] != -1) return memo[i][state];
                int ans = 0;
                if(state == 0) {
                    ans = (nums[i] == k) + max(
                        dfs(i + 1, 0),
                        dfs(i + 1, 1)
                    );
                    // if(nums[i] == k) ans += 1;
                } else if(state == 1) {
                    ans = (nums[i] == t) + max(
                        dfs(i + 1, 1),
                        dfs(i + 1, 2)
                    );
                } else if (state == 2) {
                    ans = (nums[i] == k) + dfs(i + 1, 2);
                }
                return memo[i][state] = ans;
            };
            ans = max({ans, dfs(0, 0), dfs(0, 1)});
        }
        return ans;
    }
};