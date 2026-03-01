#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int calculate(string s) {
            int n = s.size();
            stack<int> numSt;
            if(s[0] == '-') numSt.push(0);
            stack<char> opSt;
            long long num = 0;
            unordered_map<char, int> priority = {
                {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}
            };
            auto calc = [&] () {
                auto op = opSt.top(); opSt.pop();
                auto a = numSt.top(); numSt.pop();
                auto b = numSt.top(); numSt.pop();
                if(op == '+') {
                    numSt.push(b + a);
                } else if(op == '-') {
                    numSt.push(b - a);
                } else if(op == '*') {
                    numSt.push(b * a);
                } else if(op == '/') {
                    numSt.push(b / a);
                }
            };
            for(int i = 0; i < n; i ++) {
                if(s[i] == ' ') continue;
                if(isdigit(s[i])) {
                    while(i < n && isdigit(s[i])) {
                        num = num * 10 + (s[i] - '0');
                        i += 1;
                    }
                    numSt.push(num);
                    num = 0;
                    i -= 1;
                } else if(s[i] == ')') {
                    while(opSt.top() != '(') calc();
                    opSt.pop();
                } else if(s[i] == '(') {
                    if(s[i + 1] == '-') numSt.push(0);
                    opSt.push(s[i]);
                } else {
                    // + , -, * , /
                    while(!opSt.empty() && opSt.top() != '(' && priority[opSt.top()] >= priority[s[i]]) {
                        calc();
                    }
                    opSt.push(s[i]);
                }
            }
            while(!opSt.empty()) calc();
            return numSt.top();
        }
    };