// 1078. Occurrences After Bigram [E]
// LeetCode occurrences-after-bigram

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int count = 0;
        string temp = "";
        vector<string> ans;
        string f = "";
        string s = "";
        for(int i = 0; i < text.size(); i ++) {
            char c = text[i];
            if(c != ' ') {
               temp += c;
            }
            if(i == text.size() - 1 || c == ' ') {
                if(f == "") f = temp;
                else if(s == "") s = temp;
                else {
                    if(f == first && s == second) {
                        ans.push_back(temp);
                    }
                    f = s;
                    s = temp;
                }
                temp = "";
            }
             // cout << f << " " << s << endl;
                
        }
        return ans;
    }
};