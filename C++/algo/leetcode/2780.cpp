#include <bits/stdc++.h>
using namespace std;

// 2780. Minimum Index of a Valid Split [M]
// LeetCode minimum-index-of-a-valid-split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int candidate = nums[0], count = 0, candidateCount = 0, n = nums.size();
        for(int num : nums) {
            if(count == 0) candidate = num;
            count += num == candidate ? 1 : -1;
        }
        for(int num : nums) {
            if(num == candidate) candidateCount += 1;
        }
        count = 0;
        for(int i = 0; i < nums.size() - 1; i ++) {
            if(nums[i] == candidate) count += 1;
            int remainingCount = candidateCount - count;
            if(count * 2 > i + 1 && remainingCount * 2 > nums.size() - i - 1) {
                return i;
            }
        }
        return -1;
    }
};