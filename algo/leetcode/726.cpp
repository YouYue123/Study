#include <bits/stdc++.h>
using namespace std;

// 726. Number of Atoms [H]
// LeetCode number-of-atoms

class Solution {
private:
    int cursor = 0;
    string f;

    // Expression -> Term { Term }
    map<string, int> parseExpression() {
        map<string, int> res;
        while (cursor < f.size() && f[cursor] != ')') {
            auto term = parseTerm();
            for (auto& [name, cnt] : term) {
                res[name] += cnt;
            }
        }
        return res;
    }

    // Term -> Factor [Number]
    map<string, int> parseTerm() {
        map<string, int> res = parseFactor();
        int multiplier = parseNum();
        if (multiplier > 1) {
            for (auto& [name, cnt] : res) {
                cnt *= multiplier;
            }
        }
        return res;
    }

    // Factor -> Name | "(" Expression ")"
    map<string, int> parseFactor() {
        map<string, int> res;
        if (f[cursor] == '(') {
            cursor++; // skip '('
            res = parseExpression();
            cursor++; // skip ')'
        } else {
            string name = parseName();
            res[name] = 1;
        }
        return res;
    }

    string parseName() {
        string name = "";
        name += f[cursor++];
        while (cursor < f.size() && islower(f[cursor])) {
            name += f[cursor++];
        }
        return name;
    }

    int parseNum() {
        if (cursor >= f.size() || !isdigit(f[cursor])) return 1;
        int num = 0;
        while (cursor < f.size() && isdigit(f[cursor])) {
            num = num * 10 + (f[cursor++] - '0');
        }
        return num;
    }

public:
    string countOfAtoms(string formula) {
        this->f = formula;
        this->cursor = 0;
        auto dict = parseExpression();
        
        string ans = "";
        for (auto& [name, cnt] : dict) {
            ans += name;
            if (cnt > 1) ans += to_string(cnt);
        }
        return ans;
    }
};