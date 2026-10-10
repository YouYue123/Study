#include <bits/stdc++.h>
using namespace std;

// 152. Maximum Product Subarray [M]
// LeetCode maximum-product-subarray

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_min = 1;
        int cur_max = 1;
        int ans = -INF;
        for(int num : nums) {
            int tmp = cur_min;
            cur_min = min({
                num * cur_min, 
                num * cur_max,
                num
            });
            cur_max = max({
                num * tmp,
                num * cur_max, 
                num
            });
            ans = max({
                ans,
                cur_max,
            });
            // cout << cur_min << " " << cur_max << endl;
            // cout << ans << endl;
        }
        return ans;
    }
};