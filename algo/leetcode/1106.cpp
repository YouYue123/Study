#include <bits/stdc++.h>
using namespace std;

// 1106. Parsing A Boolean Expression [H]
// LeetCode parsing-a-boolean-expression

class Solution {
private:
    int cursor = 0;
    string f;
    bool parseExpression() {
        if(f[cursor] == '!') {
            // skip !(
            cursor += 2;
            bool ans = !parseExpression();
            // skip )
            cursor += 1;
            return ans;
        } else if(f[cursor] == '&') {
            // skip &(
            cursor += 2;
            bool ans = true;
            while(f[cursor] != ')') {
                if(!parseFactor()) ans = false;
                if(f[cursor] == ',') cursor += 1;
            }
            // skip )
            cursor += 1;
            return ans;
        } else if(f[cursor] == '|') {
            // skip |(
            cursor += 2;
            bool ans = false;
            while(f[cursor] != ')') {
                if(parseFactor()) ans = true;
                if(f[cursor] == ',') cursor += 1;
            }
            // skip )
            cursor += 1;
            return ans;
        } else {
            return parseFactor();
        }
    }

    bool parseFactor() {
        if(f[cursor] != 't' && f[cursor] != 'f') {
            return parseExpression();
        }
        char val = f[cursor];
        cursor += 1;
        return val == 't';
    }

public:
    bool parseBoolExpr(string expression) {
        this->f = expression;
        return parseExpression();
    }
};