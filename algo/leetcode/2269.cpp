#include <bits/stdc++.h>
using namespace std;

// 2269. Find the K-Beauty of a Number [E]
// LeetCode find-the-k-beauty-of-a-number

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cur;
        int ans = 0;
        int pow = 1;
        for(int left = num; left > 0; left /= 10) {
            cur += (left% 10) * pow;
            if(--k > 0) {
                pow *= 10;
            } else {
                if(cur && (num % cur == 0)) ans += 1;
                cur /= 10;
            }
        }
        return ans;
    }
};