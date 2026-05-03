#include <bits/stdc++.h>
using namespace std;

// 3375. Minimum Operations to Make Array Values Equal to K [E]
// LeetCode minimum-operations-to-make-array-values-equal-to-k

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, bool> dict;
        for(int num : nums) {
            if(num > k && !dict[num]) ans += 1;
            if(num < k) return -1;
            dict[num] = true; 
        }
        return ans;
    }
};