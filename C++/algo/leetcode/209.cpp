#include <bits/stdc++.h>
using namespace std;

// 209. Minimum Size Subarray Sum [M]
// LeetCode minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(right < nums.size()) {
            sum += nums[right];
            while(sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left += 1;
            }
            right += 1;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};