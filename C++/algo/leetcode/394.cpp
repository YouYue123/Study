// 394. Decode String [M]
// LeetCode decode-string

class Solution {
private:
    int cursor = 0;
    string f;
    string parseExpression() {
        string ans = "";
        while (cursor < f.size() && f[cursor] != ']') {
            if (isdigit(f[cursor])) {
                // 1. 解析数字
                int num = 0;
                while (cursor < f.size() && isdigit(f[cursor])) {
                    num = num * 10 + (f[cursor] - '0');
                    cursor++;
                }
                        
                // 2. 跳过 '['
                cursor++; 
                
                // 3. 递归解析括号内部的内容
                string nested = parseExpression();
                
                // 4. 跳过 ']'
                cursor++; 
                
                // 5. 累加结果
                while (num) {
                    ans += nested;
                    num -= 1;
                }
            } else {
                // 普通字符，直接累加
                ans += f[cursor];
                cursor += 1;
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        this->f = s;
        this->cursor = 0; // 重置游标
        return parseExpression();
    }
};