#include <bits/stdc++.h>
using namespace std;

// 523. Continuous Subarray Sum [M]
// LeetCode continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> dict;
        dict[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            int num = nums[i];
            sum += num;
            // (sum - pre_sum) % k = 0
            // sum % k = pre_sum % k
            int target = sum % k;
            if(dict.contains(target) && i - dict[target] >= 2) return true;
            if(!dict.contains(target)) dict[target] = i;
        }
        return false;
    }
};