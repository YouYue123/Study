#include <bits/stdc++.h>
using namespace std;

// 53. Maximum Subarray [M]
// LeetCode maximum-subarray

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = -INF;
        int ans = -INF;
        for(int num : nums) {
            curMax = max(curMax + num, num);
            ans = max(ans, curMax);
        }
        return ans;
    }
};