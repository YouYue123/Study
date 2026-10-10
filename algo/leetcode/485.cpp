#include <bits/stdc++.h>
using namespace std;

// 485. Max Consecutive Ones [E]
// LeetCode max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right ++) {
            if(nums[right] == 0) {
                left = right + 1;
            } else {
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};