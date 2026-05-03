#include <bits/stdc++.h>
using namespace std;

// 594. Longest Harmonious Subsequence [E]
// LeetCode longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size()) {
            while(nums[right] - nums[left] > 1) {
                left += 1;
            }
            if(nums[right] - nums[left] == 1) {
                ans = max(ans, right - left + 1);
            }
            right += 1;
        }
        return ans;
    }
};