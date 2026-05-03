#include <bits/stdc++.h>
using namespace std;

// 2845. Count of Interesting Subarrays [M]
// LeetCode count-of-interesting-subarrays

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int sum = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        long long ans = 0;
        for(int num : nums) {
            sum += ((num % mod) == k ? 1 : 0);
            // (sum - prev) % mod = k
            // sum % mod - k =   prev % mod 
            int comple = sum % mod - k;
            if(comple < 0) comple += mod;
            ans += dict[comple];
            dict[sum % mod] += 1;
        }
        return ans;
    }
};