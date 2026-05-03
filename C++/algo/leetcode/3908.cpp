#include <bits/stdc++.h>
using namespace std;

// 3908. Valid Digit Number [E]
// LeetCode valid-digit-number

class Solution {
public:
    bool validDigit(int n, int x) {
        bool found = false;
        bool start_with = false;
        while(n != 0) {
            int cur = n % 10;
            if(cur == x) {
                found = true;
                if(n / 10 == 0) start_with = true;
            }
            n /= 10;
        }
        return found && !start_with;
    }
};