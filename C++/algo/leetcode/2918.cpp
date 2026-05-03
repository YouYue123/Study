#include <bits/stdc++.h>
using namespace std;

// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros [M]
// LeetCode minimum-equal-sum-of-two-arrays-after-replacing-zeros

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroCount1 = 0, zeroCount2 = 0;
        long long sum1 = 0, sum2 = 0;
        for(int num : nums1) {
            if(num == 0) zeroCount1 += 1;
            sum1 += num;
        }
        for(int num : nums2) {
            if(num == 0) zeroCount2 += 1;
            sum2 += num;
        }
        long long total1 = sum1 + zeroCount1;
        long long  total2 = sum2 + zeroCount2;
        // cout << total1 << " " << total2 << endl;
        // cout << zeroCount1 << " " << zeroCount2 << endl;
        if(total1 > total2) {
            if(zeroCount2 == 0 || zeroCount2 + sum2 > total1 ) return -1;
        }
        if(total2 > total1) {
            if(zeroCount1 == 0 || zeroCount1 + sum1 > total2) return -1;
        }
        return max(total1, total2); 
    }
};