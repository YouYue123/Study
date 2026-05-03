#include <bits/stdc++.h>
using namespace std;

// 1006. Clumsy Factorial [M]
// LeetCode clumsy-factorial

class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        n -= 1;
        int index = 0;
        while(n > 0) {
            if(index % 4 == 0) {
                st.top() *= n;
            } else if(index % 4 == 1) {
                st.top() /= n;
            } else if(index % 4 == 2) {
                st.push(n);
            } else {
                st.push(-n);
            }
            n -= 1;
            index = (index + 1) % 4;
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        } 
        return ans;
    }
};