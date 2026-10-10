#include <bits/stdc++.h>
using namespace std;

// 3685. Subsequence Sum After Capping Elements [M]
// LeetCode subsequence-sum-after-capping-elements

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        vector<bool> ans(n);
        bitset<4001> f = 1;
        for(int x = 1; x <= n; x ++) {
            // 增量地考虑所有恰好等于 x 的数
            while (i < n && nums[i] == x) {
                f |= f << nums[i];
                i++;
            }
            // 枚举（从大于 x 的数中）选了 j 个 x
            for(int j = 0; j <= min(n - i, k  / x); j ++) {
                if(f[k - j * x]) {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};