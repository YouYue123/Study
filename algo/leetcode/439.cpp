#include <bits/stdc++.h>
using namespace std;

// 439. Ternary Expression Parser [M]
// LeetCode ternary-expression-parser

class Solution {
private:
    int cursor = 0;
    string f;
    string parseExpression() {
        bool condition = parseCond();
        cursor += 1;
        string trueVal = parseVal();
        cursor += 1;
        string falseVal = parseVal();
        return condition ? trueVal : falseVal;
    }
    bool parseCond () {
        char cond = f[cursor];
        cursor += 1;
        return cond == 'T';
    }

    string parseVal () {
        if(cursor + 1 < f.size() && f[cursor + 1] == '?') {
            return parseExpression();
        }
        string ans = "";
        while(cursor < f.size() && f[cursor] != ':') {
            ans += f[cursor];
            cursor += 1;
        }
        return ans;
    }

public:
    string parseTernary(string expression) {
        this->f = std::move(expression);
        return parseExpression();
    }
};