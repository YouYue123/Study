#include <bits/stdc++.h>
using namespace std;

// 1056. Confusing Number [E]
// LeetCode confusing-number

class Solution {
public:
    bool isValid(int i) {
        if(i == 2 || i == 3 || i == 4 || i == 5 || i == 7) {
            return false;
        }
        return true;
    }

    bool confusingNumber(int n) {
        int before = n;
        int after = 0;

        while(n != 0) {
            int cur = n % 10;
            if (!isValid(cur)) {
                return false;
            }
            if (cur == 6) {
                cur = 9;
            } else if (cur == 9) {
                cur = 6;
            }
            after = cur + after * 10;
            n /= 10;
        }
        return after != before;
    }
};