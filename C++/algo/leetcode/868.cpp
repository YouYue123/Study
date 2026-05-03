#include <bits/stdc++.h>
using namespace std;

// 868. Binary Gap [E]
// LeetCode binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        int idx = 0;
        while(n > 0) {
            int cur = n % 2;
            // cout << cur << " ";
            if(cur == 1) {
                if(prev != -1) {
                    ans = max(ans, idx - prev);
                }
                prev = idx;
            }
            n /= 2;
            idx += 1;
        }
        return ans;
    }
};