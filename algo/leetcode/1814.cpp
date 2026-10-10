#include <bits/stdc++.h>
using namespace std;

// 1814. Count Nice Pairs in an Array [M]
// LeetCode count-nice-pairs-in-an-array

class Solution {
public:
    int MOD = 1e9 + 7;
    int rev(long long x) {
        long long ans = 0;
        while(x > 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        //  nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
        unordered_map<int, long long> dict;
        long long ans = 0;
        for(int num : nums) {
            int key = num - rev(num);
            ans = (ans + dict[key]) % MOD;
            dict[key] += 1;
        }
        return ans;
    }
};