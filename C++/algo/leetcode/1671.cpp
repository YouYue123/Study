#include <bits/stdc++.h>
using namespace std;

// 1671. Minimum Number of Removals to Make Mountain Array [H]
// LeetCode minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> g, f(n);
        for(int i = n - 1; i >= 0; i --) {
            auto idx = lower_bound(g.begin(), g.end(), nums[i]) - g.begin();
            f[i] = idx + 1;
            if(idx == g.size()) g.push_back(nums[i]);
            else g[idx] = nums[i];
        }
        g.clear();
        int val = 0;
        for(int i = 0; i < n; i ++) {
            auto idx = lower_bound(g.begin(), g.end(), nums[i]) - g.begin();
            int pre = idx + 1;
            if(idx == g.size()) g.push_back(nums[i]);
            else g[idx] = nums[i];
            if(pre >= 2 && f[i] >= 2) {
                val = max(val, pre + f[i] - 1);
            }
        }
        return n - val;
    }
};