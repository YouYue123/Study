#include <bits/stdc++.h>
using namespace std;

// 2488. Count Subarrays With Median K [H]
// LeetCode count-subarrays-with-median-k

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        bool find = false;
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i ++) {
            sum += nums[i] > k ? 1 : nums[i] < k ? -1 : 0;
            find |= nums[i] == k;
            if(find) {
                ans += dict[sum];
                ans += dict[sum - 1];
            } else {
                dict[sum] = dict[sum] + 1;
            }
        }
        return ans;
    }
};