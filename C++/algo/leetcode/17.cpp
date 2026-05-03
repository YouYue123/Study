// 17. Letter Combinations of a Phone Number [M]
// LeetCode letter-combinations-of-a-phone-number

class Solution {
public:
    unordered_map<char, string> dict = {
        {'2', "abc" }, 
        {'3', "def" }, 
        {'4', "ghi"},
        {'5', "jkl"}, 
        {'6', "mno" }, 
        {'7', "pqrs" }, 
        {'8', "tuv"},
        {'9', "wxyz"}, 
    };
    vector<string> ans;
    void dfs(string& digits, string& temp) {
        int cur = temp.size();
        if(temp.size() == digits.size()) {
            ans.push_back(temp);
            return;
        }
        for(char c : dict[digits[cur]]) {
            temp += c;
            dfs(digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string temp = "";
        dfs(digits, temp);
        return ans;
    }
};