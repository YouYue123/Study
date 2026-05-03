#include <bits/stdc++.h>
using namespace std;

// 26. Remove Duplicates from Sorted Array [E]
// LeetCode remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0;
        while(p2 < n) {
            if(nums[p1] != nums[p2]) {
                p1 += 1;
                nums[p1] = nums[p2];
            }
            p2 += 1;
        }
        return p1 + 1;
    }
};