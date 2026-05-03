// 224. Basic Calculator [H]
// LeetCode basic-calculator

class Solution {
private:
    int cursor = 0;
    string s;
    int L0() {
        skip_space();
        long long ans = L1();
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
        skip_space();
        if(s[cursor] == '(') {
            cursor += 1;
            int ans = L0();
            cursor += 1;
            skip_space();
            return ans;
        }
        long long ans = 0;
        while(cursor < s.size() && isdigit(s[cursor])) {
            ans = ans * 10 + (s[cursor] - '0');
            cursor += 1;
        }
        skip_space();
        return ans;
    }
    void skip_space() {
        while(cursor < s.size() && s[cursor] == ' ') cursor += 1;
    }
public:
    int calculate(string s) {
        this->s = s;
        return L0();
    }
};