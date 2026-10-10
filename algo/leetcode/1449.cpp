#include <bits/stdc++.h>
using namespace std;

// 1449. Form Largest Integer With Digits That Add up to Target [H]
// LeetCode form-largest-integer-with-digits-that-add-up-to-target

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;
        for(int c: cost) {
            for(int j = c; j <= target; j ++) {
                f[j] = max(f[j], f[j - c] + 1);
            }
        }
        if(f[target] < 0) return "0";
        string ans = "";
        for(int i = 9; i >= 1; i --) {
            int c = cost[i - 1];
            // key: f[target - c] + 1 == f[target]
            // 保证最优路径
            while(target >= c && f[target - c] + 1 == f[target]) {
                ans += '0' + i;
                target -= c;
            }
        }
        return ans;
    }
};