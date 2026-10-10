#include <bits/stdc++.h>
using namespace std;

// 260. Single Number III [M]
// LeetCode single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bitmask = 0;
        for(int num : nums) bitmask ^= num;
        // rightmost 1-bit diff between x and y
        long diff = bitmask & -bitmask;
        long x = 0;
        for(int num : nums) {
            if (num & diff) x ^= num;
        }

        return { (int)x, (int)(bitmask ^ x) };
    }
};