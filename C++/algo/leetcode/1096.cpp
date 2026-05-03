// 1096. Brace Expansion II [H]
// LeetCode brace-expansion-ii

class Solution {
private:
    int cursor = 0;
    string f;
    set<string> parseExpression () {
        auto ans = parseTerm();
        while(cursor < f.size()) {
            if(f[cursor] != ',') break;
            cursor += 1;
            auto neseted = parseTerm();
            ans.insert(neseted.begin(), neseted.end());
        }
        return ans;
    }
    set<string> parseTerm() {
        auto ans = parseFactor();
        // cout << "factor: " << ans.size() << endl;
        while(cursor < f.size()) {
            if(f[cursor] == ',' || f[cursor] == '}') break;
            auto nested = parseFactor();
            set<string> tmp;
            for(auto& s1 : ans) {
                for(auto& s2 : nested) {
                    // cout << s1 << " " << s2 << endl;
                    tmp.insert(s1 + s2);
                }
            }
            ans = std::move(tmp);
        }
        return ans;
    }
    set<string> parseFactor() {
        if(f[cursor] == '{') {
            cursor += 1;
            auto nested = parseExpression();
            cursor += 1;
            return nested;
        }
        set<string> ans;
        string s = "";
        while(cursor < f.size() && isalpha(f[cursor])) {
            s += f[cursor];
            cursor += 1;
        }
        ans.insert(s);
        return ans;
    }
public:
    vector<string> braceExpansionII(string expression) {
        this->f = expression;
        auto ansSet = parseExpression();
        return vector<string>(ansSet.begin(), ansSet.end());
    }
};