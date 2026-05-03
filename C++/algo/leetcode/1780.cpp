#include <bits/stdc++.h>
using namespace std;

// 1780. Check if Number is a Sum of Powers of Three [M]
// LeetCode check-if-number-is-a-sum-of-powers-of-three

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 0) {
            if(n % 3 == 2) {
                return false;
            } 
            n /= 3;
        }
        return true;
    }
};