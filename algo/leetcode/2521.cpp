#include <bits/stdc++.h>
using namespace std;

// 2521. Distinct Prime Factors of Product of Array [M]
// LeetCode distinct-prime-factors-of-product-of-array

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> dict;
        for(int num : nums) {
            for(int p = 2; p * p <= num; p += 1) {
                if(num % p == 0) {
                    dict.insert(p);
                }
                while(num % p == 0) num /= p;
            }
            if(num != 1) dict.insert(num);
        }
        return dict.size();
    }
};