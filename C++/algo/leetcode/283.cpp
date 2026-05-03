#include <bits/stdc++.h>
using namespace std;

// 283. Move Zeroes [E]
// LeetCode move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroPos = 0, nonZeroPos = 0;
        while(nonZeroPos < n) {
            while(zeroPos < n && nums[zeroPos] != 0) zeroPos += 1;
            nonZeroPos = zeroPos + 1;
            while(nonZeroPos < n && nums[nonZeroPos] == 0) nonZeroPos += 1;
            // cout << zeroPos << " " << nonZeroPos << endl;
            if(zeroPos < n && nonZeroPos < n) {
                swap(nums[zeroPos], nums[nonZeroPos]);
                zeroPos += 1;
            } else {
                break;
            }

        }
    }
};