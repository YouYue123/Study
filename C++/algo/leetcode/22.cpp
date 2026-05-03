#include <bits/stdc++.h>
using namespace std;

// 22. Generate Parentheses [M]
// LeetCode generate-parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        auto dfs = [&] (this auto&& dfs, string& tmp, int open_cnt) {
            if(tmp.size() == n * 2) {
                if(open_cnt == 0) ans.push_back(tmp);
                return;
            }
            if(open_cnt < n) {
                tmp.push_back('(');
                dfs(tmp, open_cnt + 1);
                tmp.pop_back();
            }
            if(open_cnt > 0) {
                tmp.push_back(')');
                dfs(tmp, open_cnt - 1);
                tmp.pop_back();
            }
        };
        string tmp = "";
        dfs(tmp, 0);
        return ans;
    }
};