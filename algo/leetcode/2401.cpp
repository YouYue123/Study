#include <bits/stdc++.h>
using namespace std;

// 2401. Longest Nice Subarray [M]
// LeetCode longest-nice-subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int ans = 0;
        int or_ = 0;
        while(right < nums.size()) {
            while (or_ & nums[right]) { // 有交集
                or_ ^= nums[left];  // 从 or 中去掉集合 nums[left]
                left += 1;
            }
            or_ |= nums[right]; // 把集合 nums[right] 并入 or 中
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};