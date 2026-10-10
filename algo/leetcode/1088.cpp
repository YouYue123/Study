#include <bits/stdc++.h>
using namespace std;

// 1088. Confusing Number II [H]
// LeetCode confusing-number-ii

class Solution {
public:
    // d[i] is the original no, d[i+5] is number after rotation
    int d[10] = {0, 1, 6, 8, 9, 0, 1, 9, 8, 6};
    // n -> limit
    
    int confusingNumberII(int n, int curNum = 0, int postRotate = 0, long pos = 1) {
        int ans = curNum == postRotate ? 0 : 1;
        int start = pos == 1 ? 1 : 0;
        for (int i = start; i < 5; i++)
            if (curNum <= (n - d[i]) / 10)
                ans += confusingNumberII(n, curNum * 10 + d[i], d[i+5] * pos + postRotate, pos * 10);
        return ans;
    }
};