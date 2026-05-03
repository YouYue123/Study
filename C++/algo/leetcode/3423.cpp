#include <bits/stdc++.h>
using namespace std;

// 3423. Maximum Difference Between Adjacent Elements in a Circular Array [E]
// LeetCode maximum-difference-between-adjacent-elements-in-a-circular-array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int left = 0, right = 1;
        int ans = abs(nums[0] - nums.back());
        while(right < nums.size()) {
            ans = max(ans, abs(nums[left] - nums[right]));
            left += 1;
            right += 1;
        }
        return ans;
    }
};