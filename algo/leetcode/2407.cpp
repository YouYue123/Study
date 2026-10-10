#include <bits/stdc++.h>
using namespace std;

// 2407. Longest Increasing Subsequence II [H]
// LeetCode longest-increasing-subsequence-ii

class Solution {
public:
    vector<int> max;
    void modify(int o, int l, int r, int i, int val) {
        if(l == r) {
            max[o] = val;
            return;
        }
        int m = l + (r - l) / 2;
        if(i <= m) modify(o * 2, l , m, i ,val);
        else modify(o * 2 + 1, m + 1, r, i, val);
        max[o] = std::max(max[o * 2], max[o * 2 + 1]);
    }
    // RMQ
    int query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) return max[o];
        int ans = 0;
        int m = l + (r - l) / 2;
        if(L <= m) ans = query(o * 2, l, m, L, R);
        if(R > m) ans = std::max(ans, query(o * 2 + 1, m + 1, r, L, R));
        return ans;
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        // f[i][num]
        // if num != nums[i] -> f[i][num] = f[i - 1][num]
        // if num == nums[i] -> f[i][num] = f[i - 1][num'] 
        // num - k <= num' < num, f[i][num] = 1 + max(f[i - 1][num']), RMQ
        int u = *max_element(nums.begin(), nums.end());
        max.resize(u * 4);
        for(int x : nums) {
            if(x == 1) modify(1, 1, u, 1, 1);
            else {
                int ans = 1 + query(1, 1, u, std::max(x - k, 1), x - 1);
                modify(1, 1, u, x, ans);
            }
        }
        return max[1];
    }
};