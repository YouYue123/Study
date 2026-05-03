#include <bits/stdc++.h>
using namespace std;

// 1295. Find Numbers with Even Number of Digits [E]
// LeetCode find-numbers-with-even-number-of-digits

class Solution {
public:
    int getDigit(int i) {
        int ans = 0;
        while(i > 0) {
            ans += 1;
            i /= 10;
        }
        return ans;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            if(getDigit(num) % 2 == 0) ans += 1;
        }
        return ans;
    }
};