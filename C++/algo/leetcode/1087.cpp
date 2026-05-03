// 1087. Brace Expansion [M]
// LeetCode brace-expansion

class Solution {
private:
    int cursor = 0; // 当前解析到的字符位置指针
    string f;       // 存储输入的原始字符串

    /**
     * L0 层：处理“并列/选择”关系 (Union)
     * 对应语法中的逗号 ','。例如 {a,b,c} 中的 a、b、c 是并列关系。
     */
    set<string> L0 () {
        auto ans = L1(); // 先获取第一个待选项
        while(cursor < f.size()) {
            if(f[cursor] != ',') break; // 如果不是逗号，说明并列关系结束
            cursor += 1; // 跳过逗号
            set<string> nextItem = L1(); // 获取下一个并列项
            // 将新项合并到结果集中（Set 自动去重并排序）
            ans.insert(nextItem.begin(), nextItem.end());
        }
        return ans;
    }

    /**
     * L1 层：处理“连接/拼接”关系 (Concatenation)
     * 处理连续出现的项，如 a{b,c}。将前面的结果与后面的结果做笛卡尔积。
     */
    set<string> L1() {
        auto ans = L2(); // 获取第一个单元
        // 当还没结束，且不是逗号或右括号时，说明后面紧跟着另一个需要拼接的单元
        while(cursor < f.size() && f[cursor] != ',' && f[cursor] != '}') {
            auto nxt = L2(); // 获取紧跟的下一个单元
            set<string> combined;
            // 核心逻辑：双重循环实现笛卡尔积拼接 (Cartesian Product)
            // 例如：ans{"a", "b"} + nxt{"c", "d"} -> {"ac", "ad", "bc", "bd"}
            for(auto& s1 : ans) {
                for(auto& s2 : nxt) {
                    combined.insert(s1 + s2);
                }
            }
            ans = combined;
        }
        return ans;
    }

    /**
     * L2 层：处理“原子单元” (Atomic Unit)
     * 处理最小单位：要么是单个字母组成的字符串，要么是递归处理花括号 {} 内部的内容。
     */
    set<string> L2() {
        set<string> ans;
        if(f[cursor] == '{') {
            // 遇到左括号：进入嵌套递归
            cursor += 1;   // 跳过 '{'
            ans = L0();    // 递归调用最高层逻辑解析括号内部
            cursor += 1;   // 跳过 '}'
        } else {
            // 遇到字母：读取完整的字符串
            string s = "";
            while(cursor < f.size() && isalpha(f[cursor])) {
                s += f[cursor];
                cursor += 1;
            }
            ans.insert(s);
        }
        return ans;
    }

public:
    vector<string> expand(string s) {
        this->f = s;
        this->cursor = 0; // 重置指针
        auto resultSet = L0(); // 从最高层级开始解析
        // 将 set 转为 vector 返回（set 保证了结果已按字典序排序）
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};