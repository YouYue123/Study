#include <bits/stdc++.h>
using namespace std;

// 1004. Max Consecutive Ones III [M]
// LeetCode max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int flip_cnt = 0;
        int ans = 0;
        while(right < n) {
            if(nums[right] == 0) {
                flip_cnt += 1;
            }
            while(flip_cnt > k) {
                if(nums[left] == 0) flip_cnt -= 1;
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right += 1;
        }
        return ans;
    }
};