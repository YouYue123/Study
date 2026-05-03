// 770. Basic Calculator IV [H]
// LeetCode basic-calculator-iv

class Solution {
    //两个不同的变量名称str1,str2按照字典序组合为一个新的变量名称newVarName
    //例如 str1 = a*c, str2 = b*d ,组合后得到 a*b*c*d
    string combineNewVarName(string str1, string str2) {
        vector<string> A;

        str1 += '*';
        int pos = str1.find("*", 0);
        while (pos != str1.npos) {
            string temp = str1.substr(0, pos);
            A.push_back(temp);
            str1 = str1.substr(pos + 1, str1.size());
            pos = str1.find("*", 0);
        }

        str2 += '*';
        pos = str2.find("*", 0);
        while (pos != str2.npos) {
            string temp = str2.substr(0, pos);
            A.push_back(temp);
            str2 = str2.substr(pos + 1, str2.size());
            pos = str2.find("*", 0);
        }

        sort(A.begin(), A.end());
        string newVarName = A[0];
        for (int i = 1; i < A.size(); i++) {
            newVarName += "*";
            newVarName += A[i];
        }
        return newVarName;
    }

    //从字符串idx位置开始，获取一个新操作数
    map<string, int> getOne(string &str, int& idx) {
        map<string, int> res;
        res["@"] = 0;
        int n = str.size();
        if (idx >= n) return res;
        int start = idx;
        if (str[idx] == '(') { //将括号表达式的计算结果返回
            stack<int> s;
            s.push(idx++);
            while (idx < n && !s.empty()) {
                if (str[idx] == '(') s.push(idx);
                if (str[idx] == ')') s.pop();
                idx++;
            }
            string substr = str.substr(start + 1, idx - start - 2);
            res = calculator(substr);
        } else if (isdigit(str[idx])) { //操作数是一个数字
            while (idx < n && isdigit(str[idx])) idx++;
            string val = str.substr(start, idx - start);
            res["@"] = stoi(val);
        } else { //操作数是一个变量
            while (idx < n && str[idx] != ' ') idx++;
            string varName = str.substr(start, idx - start);
            if (hashtable.count(varName)) res["@"] = hashtable[varName];
            else { res[varName] = 1; }
        }
        idx += 1;
        return res;
    }

    //定义新的加法操作
    map<string, int> add(map<string, int> &A, map<string, int> &B) {
        map<string, int> C = A;
        for (auto &x:B) {
            if (C.count(x.first)) {
                C[x.first] += x.second;
            } else {
                C[x.first] = x.second;
            }
        }
        return C;
    }

    //定义新的减法操作
    map<string, int> sub(map<string, int> &A, map<string, int> &B) {
        map<string, int> C = A;
        for (auto &x:B) {
            if (C.count(x.first)) {
                C[x.first] -= x.second;
            } else {
                C[x.first] = -x.second;
            }
        }
        return C;
    }

    //定义新的乘法操作
    map<string, int> mul(map<string, int> &A, map<string, int> &B) {
        map<string, int> C;
        C["@"] = 0;
        for (auto &a:A) {
            for (auto &b:B) { 
                if (a.first == "@") { // a是常数
                    if (C.count(b.first)) {
                        C[b.first] += a.second * b.second;
                    } else {
                        C[b.first] = a.second * b.second;
                    }
                } else if (b.first == "@") { //b是常数
                    if (C.count(a.first)) {
                        C[a.first] += a.second * b.second;
                    } else {
                        C[a.first] = a.second * b.second;
                    }
                } else { //a b 都不是常数，则需要合成新的变量名称
                    string newVarName = combineNewVarName(a.first, b.first); 
                    if (C.count(newVarName)) {
                        C[newVarName] += a.second * b.second;
                    } else {
                        C[newVarName] = a.second * b.second;
                    }
                }
            }
        }
        return C;
    }

    //基于新元素操作的计算器
    map<string,int> calculator(string expression) {
        if(expression.empty()) return {};
        map<string, int> res, curRes;
        res["@"] = 0;
        curRes["@"] = 0;
        expression += " +";
        int n = expression.size();
        char op = '+';
        for (int i = 0; i < n; i += 2) {
            map<string, int> x = getOne(expression, i);
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || i == n - 1) {
                switch (op) {
                    case '+':
                        curRes = add(curRes, x);
                        break;
                    case '-':
                        curRes = sub(curRes, x);
                        break;
                    case '*':
                        curRes = mul(curRes, x);
                        break;
                }
                if (expression[i] == '+' || expression[i] == '-' || i == n - 1) {
                    res = add(res, curRes);
                    curRes.clear();
                    curRes["@"] = 0;
                }
                op = expression[i];
            }
        }
        return res;
    }

public:
    unordered_map<string,int> hashtable;
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        //使用哈希表将变量与其值对应起来
        for (int i = 0; i < evalvars.size(); i++) {
            hashtable[evalvars[i]] = evalints[i];
        }

        //使用基于新操作数的计算器计算出表达式的结果，结果以新操作数的形式返回
        map<string, int> tree = calculator(expression);

        //整理、排序输出最终的结果
        //排序的规则是：变量排在常数前面，变量名称中含有的子变量越多，排序越靠前；变量名称中的子变量数目相同，则按照字典序进行排序
        // 比如运算结果：-99*z*z*z*z*z 9*a*b*c*d 6*b*b*b 5*a*b 1*a 2*b 3*c 18 是合法的排序
        vector<pair<int,string>> sortVec;
        for(auto &x:tree){
            if (x.second != 0 && x.first != "@") {
                string str = x.first;
                str += '*';
                int cnt = 0;
                int pos = str.find("*", 0);
                while (pos != str.npos) {
                    cnt++;
                    str = str.substr(pos + 1, str.size());
                    pos = str.find("*", 0);
                }
                sortVec.push_back({cnt, x.first});
            }
        }

        sort(sortVec.begin(), sortVec.end(),[](pair<int,string> A, pair<int, string> B){
            return A.first != B.first ? A.first > B.first : A.second < B.second;
        });

        vector<string> ans(sortVec.size());
        int constant = tree["@"];
        for (int i = 0; i < sortVec.size(); i++) {
            ans[i] = to_string(tree[sortVec[i].second]) + "*" + sortVec[i].second;
        }

        if (constant != 0) ans.push_back(to_string(constant));

        return ans;
    }
};