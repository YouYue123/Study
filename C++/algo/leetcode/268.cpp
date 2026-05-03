#include <bits/stdc++.h>
using namespace std;

// 268. Missing Number [E]
// LeetCode missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i ++) ans ^= i;
        for(int num : nums) ans ^= num;
        return ans;
    }
};