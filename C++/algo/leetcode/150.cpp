// 150. Evaluate Reverse Polish Notation [M]
// LeetCode evaluate-reverse-polish-notation

class Solution {
public:
    bool isNum (string& s) {
        try {
            stoi(s);
            return true;
        } catch(const std::invalid_argument& ia) {
            return false;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> numSt;
        stack<char> opSt;
        for(auto& token : tokens) {
            if(isNum(token)) {
                numSt.push(stoi(token));
            } else {
                int a = numSt.top(); numSt.pop();
                int b = numSt.top(); numSt.pop();
                if(token == "+") {
                    numSt.push(a + b);
                } else if(token == "-") {
                    numSt.push(b - a);
                } else if(token == "*") {
                    numSt.push(a * b);
                }  else if(token == "/"){
                    numSt.push(b / a);
                }
            }
        }
        return numSt.top();
    }
};