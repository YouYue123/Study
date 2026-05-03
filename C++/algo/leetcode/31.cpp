#include <bits/stdc++.h>
using namespace std;

// 31. Next Permutation [M]
// LeetCode next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i -= 1;
        }
        if(i >= 0) {
            int j = n - 1;
            while(j >= i && nums[j] <= nums[i]) {
                j -= 1;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};