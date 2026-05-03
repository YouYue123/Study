#include <bits/stdc++.h>
using namespace std;

// 995. Minimum Number of K Consecutive Bit Flips [H]
// LeetCode minimum-number-of-k-consecutive-bit-flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> diff(nums.size() + 1, 0);
        int cur = 0, ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            cur += diff[i];
            if((nums[i] + cur) % 2 == 0) {
                if(i + k > nums.size()) return -1;
                cur += 1;
                ans += 1;
                diff[i + k] -= 1;
            }
        }
        return ans;
    }
};