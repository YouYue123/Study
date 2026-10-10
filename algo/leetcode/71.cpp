#include <bits/stdc++.h>
using namespace std;

// 71. Simplify Path [M]
// LeetCode simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> st;
        int cursor = 0;
        while(cursor < n) {
            if(path[cursor] != '/') {
                string tmp = "";
                while(cursor < n && path[cursor] != '/') {
                    tmp += path[cursor];
                    cursor += 1;
                }
                if(tmp == ".") {
                    continue;
                }  else if(tmp == "..") {
                    if(!st.empty()) st.pop_back();
                } else {
                    st.push_back(tmp);
                }
            } else {
                while(cursor < n && path[cursor] == '/') cursor += 1;
            }
        }
        if(st.empty()) return "/";
        // vector<string> ans;
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        string ans = "";
        for(auto& item : st) {
            // cout << st[i] << endl;
            ans += '/';
            ans += item;
        }
        return ans;
    }
};