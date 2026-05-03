#include <bits/stdc++.h>
using namespace std;

// 487. Max Consecutive Ones II [M]
// LeetCode max-consecutive-ones-ii

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int flipCnt = 0;
        int ans = 0;
        for(int right = 0; right < n; right += 1) {
            if(nums[right] == 0) flipCnt += 1;
            while(flipCnt > 1) {
                if(nums[left] == 0) flipCnt -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};