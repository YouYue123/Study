#include <bits/stdc++.h>
using namespace std;

// 3871. Count Commas in Range II [M]
// LeetCode count-commas-in-range-ii

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long thres = 999;
        while(n > thres) {
            ans += (n - thres);
            thres = thres * 1000 + 999;
        }
        return ans;
    }
};