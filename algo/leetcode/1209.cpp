#include <bits/stdc++.h>
using namespace std;

// 1209. Remove All Adjacent Duplicates in String II [M]
// LeetCode remove-all-adjacent-duplicates-in-string-ii

struct Item {
    char c;
    int cnt;
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<Item> st;
        for(char c : s) {
            if(st.empty()) {
                st.emplace(c, 1);
            } else {
                if(st.top().c == c) {
                    st.top().cnt += 1;
                    if(st.top().cnt == k) {
                        st.pop();
                    }
                } else {
                    st.emplace(c, 1);
                }
            }
        }
        // if(!st.empty() && st.top().cnt >= k) {
        //     st.pop();
        // }
        string ans = "";
        // cout << st.size() << endl;
        while(!st.empty()) {
            auto cur = st.top();
            st.pop();
            for(int i = 0; i < cur.cnt; i ++) {
                ans += cur.c;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;   
    }
};