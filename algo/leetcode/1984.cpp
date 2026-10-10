#include <bits/stdc++.h>
using namespace std;

// 1984. Minimum Difference Between Highest and Lowest of K Scores [E]
// LeetCode minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int ans = INT_MAX;
        while(right < nums.size()) {
            if(right - left + 1 > k) {
                left += 1;
            }
            if(right - left + 1 == k) {
                ans = min(ans, nums[right] - nums[left]);
            }
            right += 1;
        }
        return ans;
    }
};