#include <bits/stdc++.h>
using namespace std;

// 2270. Number of Ways to Split Array [M]
// LeetCode number-of-ways-to-split-array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> presum(nums.size(), 0);
        presum[0] = nums[0];
        int ans = 0;
        for(int i = 1; i < nums.size(); i ++) {
            presum[i] = presum[i-1] + nums[i];
        }
        for(int i = 0; i < nums.size() - 1; i ++) {
            long long firstHalf = presum[i];
            long long secondHalf = presum[nums.size() - 1] - presum[i];
            if(firstHalf >= secondHalf) ans += 1;
        }
        return ans;
    }
};