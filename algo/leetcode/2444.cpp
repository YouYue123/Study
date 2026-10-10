#include <bits/stdc++.h>
using namespace std;

// 2444. Count Subarrays With Fixed Bounds [H]
// LeetCode count-subarrays-with-fixed-bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int leftBound = -1;
        int minPos = -1, maxPos = -1;
        long long ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(nums[i] > maxK || nums[i] < minK) leftBound = i;
            if(nums[i] == minK) minPos = i;
            if(nums[i] == maxK) maxPos = i;
            ans += max(0, min(minPos, maxPos) - leftBound);
        }
        return ans;
    }
};