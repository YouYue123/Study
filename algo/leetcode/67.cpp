#include <bits/stdc++.h>
using namespace std;

// 67. Add Binary [E]
// LeetCode add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int p = a.size() - 1, q = b.size() - 1;
        int carry = 0;
        string ans = "";
        while(p >= 0 || q >= 0) {
            int cur = carry;
            if(p >= 0) {
                cur += a[p] - '0';
                p -= 1;
            }
            if(q >= 0) {
                cur += b[q] - '0';
                q -= 1;
            }
            carry = cur / 2;
            cur = cur % 2;
            ans += cur + '0';
        }
        if(carry == 1) ans += carry + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};