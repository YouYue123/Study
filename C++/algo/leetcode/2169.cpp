#include <bits/stdc++.h>
using namespace std;

// 2169. Count Operations to Obtain Zero [E]
// LeetCode count-operations-to-obtain-zero

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                ans += num1 / num2;
                num1 = num1 % num2;
            } else {
                ans += num2 / num1;
                num2 = num2 % num1;
            }
        }
        return ans;
    }
};