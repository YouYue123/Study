#include <bits/stdc++.h>
using namespace std;

// 772. Basic Calculator III [H]
// LeetCode basic-calculator-iii

class Solution {
private:
    int cursor = 0;
    string s;
    int L0() {
        int ans = L1();
        while(cursor < s.size()) {
            if(s[cursor] != '+' && s[cursor] != '-') break;
            char op = s[cursor];
            cursor += 1;
            int nxt = L1();
            ans = (op == '+' ? ans + nxt : ans - nxt); 
        }
        return ans;
    }
    int L1() {
        int ans = L2();
        while(cursor < s.size()) {
            if(s[cursor] != '*' && s[cursor] != '/') break;
            char op = s[cursor];
            cursor += 1;
            int nxt = L2();
            ans = (op == '*' ? ans * nxt : ans / nxt);
        }
        return ans;
    }
    int L2() {
        if(s[cursor] == '(') {
            cursor += 1;
            int ans = L0();
            cursor += 1;
            return ans;
        }
        int ans = 0;
        while(cursor < s.size() && isdigit(s[cursor])) {
            ans = ans * 10 + (s[cursor] - '0');
            cursor += 1;
        }
        return ans;
    }
public:
    int calculate(string s) {
        this->s = s;
        return L0();
    }
};