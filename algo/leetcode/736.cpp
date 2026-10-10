#include <bits/stdc++.h>
using namespace std;

// 736. Parse Lisp Expression [H]
// LeetCode parse-lisp-expression

using hashmap = unordered_map<string, int>;

class Solution {
private:
    int cursor = 0;
    string f;
    string parseToken() {
        string ans = "";
        while(cursor < f.size() && f[cursor] != ' ' && f[cursor] != ')') {
            ans += f[cursor];
            cursor += 1;
        }
        return ans;
    }
    int parseExpression(hashmap env) {
        skipSpace();
        if(f[cursor] == '(') {
            cursor += 1;
            string token = parseToken();
            int ans = 0;
            if(token == "let") {
                ans = parseLet(env);
            } else if(token == "add") {
                ans = parseAdd(env);
            } else {
                ans = parseMult(env);
            }
            cursor += 1;
            return ans;
        } else {
            string token = parseToken();
            if(isNum(token)) return stoi(token);
            return env[token];
        }
    }
    int parseLet (hashmap& env) {
        while(true) {
            skipSpace();
            if(f[cursor] == '(' ) {
                return parseExpression(env);
            }
            string var = parseToken();
            skipSpace();
            if(f[cursor] == ')') {
                if(isNum(var)) return stoi(var);
                return env[var];
            }
            int val = parseExpression(env);
            env[var] = val;
            skipSpace();
        }
    }
    
    int parseAdd(hashmap& env) {
        skipSpace();
        int v1 = parseExpression(env);
        skipSpace();
        int v2 = parseExpression(env);
        return v1 + v2;
    }

    int parseMult(hashmap& env) {
        skipSpace();
        int v1 = parseExpression(env);
        skipSpace();
        int v2 = parseExpression(env);
        return v1 * v2;
    }

    bool isNum (string& s) {
        if(s.empty()) return false;
        return isdigit(s[0]) || s[0] == '-';
    }
    void skipSpace () {
        while(cursor < f.size() && f[cursor] == ' ') {
            cursor += 1;
        }
    }
public:
    int evaluate(string expression) {
        this->f = expression;
        hashmap globalEnv;
        return parseExpression(globalEnv);
    }
};