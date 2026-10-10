#include <bits/stdc++.h>
using namespace std;

// 1879. Minimum XOR Sum of Two Arrays [H]
// LeetCode minimum-xor-sum-of-two-arrays

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector memo(1 << n, -1);
        auto dfs = [&] (this auto&& dfs, int state) {
            int i = __builtin_popcount(state);
            if(i == n) return 0;
            if(memo[state] != -1) return memo[state];
            int ans = INF;
            for(int j = 0; j < n; j ++) {
                if(state & (1 << j)) continue;
                ans = min(
                    ans,
                    dfs(state | (1 << j)) + (nums1[i] ^ nums2[j])
                );
            }
            return memo[state] = ans;
        };
        return dfs(0);
    }
};