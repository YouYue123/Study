#include <bits/stdc++.h>
using namespace std;

// 481. Magical String [M]
// LeetCode magical-string

class Solution {
public:
    int magicalString(int n) {
        // if(n <= 3) return 1;
        string s = "122";
        char cur = '1';
        int p0 = 2, p1 = 2;
        int ans = 1;
        while(s.size() < n) {
            int num = s[p0] - '0';
            while(num) {
                s.push_back(cur);
                if(cur == '1') ans += 1;
                if(s.size() == n) break;
                num -= 1;
            }
            if(cur == '1') cur = '2';
            else cur = '1';
            p0 += 1;
        }
        // cout << s << endl;
        return ans;
    }
};