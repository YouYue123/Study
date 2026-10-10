#include <bits/stdc++.h>
using namespace std;

// 3397. Maximum Number of Distinct Elements After Operations [M]
// LeetCode maximum-number-of-distinct-elements-after-operations

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int pre = INT_MIN;
        for(int x : nums) {
            x = clamp(pre + 1, x - k, x + k);
            cout << x << endl;
            if(x != pre) {
                ans += 1;
                pre = x;
            }
        }
        return ans;
     }
};