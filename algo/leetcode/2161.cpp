#include <bits/stdc++.h>
using namespace std;

// 2161. Partition Array According to Given Pivot [M]
// LeetCode partition-array-according-to-given-pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0;
        int equal = 0;
        for (int num : nums) {
            if (num < pivot) {
                less += 1;
            } else if (num == pivot) {
                equal += 1;
            }
        }
        vector<int> ans(nums.size(), 0);
        int lessI = 0;
        int equalI = less;
        int greatI = less + equal;
        for (int num : nums) {
            if(num < pivot) {
                ans[lessI] = num;
                lessI += 1;
            } else if(num == pivot) {
                ans[equalI] = num;
                equalI += 1;
            } else {
                ans[greatI] = num;
                greatI += 1;
            }
        }
        return ans;
    }
};