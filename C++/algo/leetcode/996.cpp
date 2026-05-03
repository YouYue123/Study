#include <bits/stdc++.h>
using namespace std;

// 996. Number of Squareful Arrays [H]
// LeetCode number-of-squareful-arrays

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int full = (1 << n) - 1;
        sort(nums.begin(), nums.end());
        auto isValid = [&] (int a, int b) {
            if(a < 0 || b < 0) return true;
            int sq = sqrt(a + b);
            return (a + b) == (sq * sq);
        };
        vector<unordered_map<int, int>> memo(1 << n);
        auto dfs = [&] (this auto&& dfs, int state, int prev) {
            if(full == state) return 1;
            if(memo[state].contains(prev)) return memo[state][prev];
            int ans = 0;
            int seen = -1;
            for(int k = 0; k < n; k ++) {
                if(state & (1 << k)) continue;
                if(seen != -1 && seen == nums[k]) continue;
                // cout << prev << " " << nums[k] << endl;
                // cout << (isValid(prev, nums[k]) ? "Valid" : "Not Valid") << endl;
                if(isValid(prev, nums[k])) {
                    seen = nums[k];
                    ans += dfs(state | (1 << k), nums[k]);
                }
            }
            return memo[state][prev] = ans;
        };

        return dfs(0, -1);
    }
};