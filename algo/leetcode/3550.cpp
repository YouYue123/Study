#include <bits/stdc++.h>
using namespace std;

// 3550. Smallest Index With Digit Sum Equal to Index [E]
// LeetCode smallest-index-with-digit-sum-equal-to-index

class Solution {
public:
    int sumDigit(int x) {
        int ans = 0;
        while(x != 0) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++) {
            if(sumDigit(nums[i]) == i) return i;
        }
        return -1;
    }
};