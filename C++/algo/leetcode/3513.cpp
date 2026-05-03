#include <bits/stdc++.h>
using namespace std;

// 3513. Number of Unique XOR Triplets I [M]
// LeetCode number-of-unique-xor-triplets-i

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        //  nums.size()
        // 3 2 1
        int n = nums.size();
        if(n < 3) return n;
        // cout << (int)(log(n) /log(2))  + 1 << endl;
        return pow(2, (int)(log(n) /log(2))  + 1);
        // 2 -->2 
        // 3 --> 4
        // 4-7 --> 8
        // 8-15 -->16
        // 16->31 --> 32
        // 32->63 --> 64
    }
};