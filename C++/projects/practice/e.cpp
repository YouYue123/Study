#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 执行基础运算
int applyOp(int a, int b, char op) {
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// 定义优先级
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int evaluate(string tokens) {
    stack<int> values;
    stack<char> ops;

    for(int i = 0; i < tokens.length(); i++) {
        if(tokens[i] == ' ') continue;

        if(tokens[i] == '(') {
            ops.push(tokens[i]);
        } else if(isdigit(tokens[i])) {
            int val = 0;
            while(i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        } else if(tokens[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); // 弹出 '('
        } else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    while(!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

#include <vector>
#include <cmath>

bool solve(vector<double>& nums, double target) {
    if (nums.size() == 1) {
        return abs(nums[0] - target) < 1e-6; // 处理浮点精度
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j) continue;

            vector<double> next_nums;
            for (int k = 0; k < nums.size(); ++k) {
                if (k != i && k != j) next_nums.push_back(nums[k]);
            }

            // 尝试四种运算
            vector<double> results = {nums[i] + nums[j], nums[i] - nums[j], nums[i] * nums[j]};
            if (abs(nums[j]) > 1e-6) results.push_back(nums[i] / nums[j]);

            for (double res : results) {
                next_nums.push_back(res);
                if (solve(next_nums, target)) return true;
                next_nums.pop_back(); // 回溯
            }
        }
    }
    return false;
}