#include <bits/stdc++.h>
using namespace std;

// 1567. Maximum Length of Subarray With Positive Product [M]
// LeetCode maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negLen = 0, posLen = 0;
        int ans = 0;
        for(int num : nums) {
            int prevPosLen = posLen;
            int prevNegLen = negLen;
            if(num == 0) {
                posLen = 0;
                negLen = 0;
            } else if(num > 0) {
                posLen = prevPosLen + 1;
                negLen = prevNegLen > 0 ? prevNegLen + 1 : 0;
            } else {
                posLen = prevNegLen > 0 ? prevNegLen + 1 : 0;
                negLen = prevPosLen + 1;
            }
            ans = max(ans, posLen);
        }
        return ans;
    }
};