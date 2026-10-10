#include <bits/stdc++.h>
using namespace std;

// 2779. Maximum Beauty of an Array After Applying Operation [M]
// LeetCode maximum-beauty-of-an-array-after-applying-operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size()) {
            while(nums[right] - nums[left] > 2*k) {
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};