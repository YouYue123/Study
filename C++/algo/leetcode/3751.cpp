#include <bits/stdc++.h>
using namespace std;

// 3751. Total Waviness of Numbers in Range I [M]
// LeetCode total-waviness-of-numbers-in-range-i

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        auto calc = [&](int num) {
            string numS = to_string(num);
            int n = numS.size();
            if(n < 3) return 0;
            int ans = 0;
            for(int i = 1; i < n - 1; i ++) {
                int cur = numS[i] - '0';
                int left = numS[i - 1] - '0';
                int right = numS[i + 1] - '0';
                if(cur > left && cur > right) ans += 1;
                else if(cur < left && cur < right) ans += 1;
            }
            return ans;
        };
        for(int num = num1; num <= num2; num += 1) {
            ans += calc(num);
        }
        return ans;
    }
};