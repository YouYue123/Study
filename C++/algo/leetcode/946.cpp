#include <bits/stdc++.h>
using namespace std;

// 946. Validate Stack Sequences [M]
// LeetCode validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for(int i = 0; i < pushed.size(); i ++) {
            st.push(pushed[i]);
            while(!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j += 1;
            }
        }
        return st.empty();
    }
};