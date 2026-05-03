#include <bits/stdc++.h>
using namespace std;

// 136. Single Number [E]
// LeetCode single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;
       for(int num : nums) ans ^= num;
       return ans;
    }
};