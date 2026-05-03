#include <bits/stdc++.h>
using namespace std;

// 385. Mini Parser [M]
// LeetCode mini-parser

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int n = s.size();
        if(s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        for(int i = 0; i < n; i ++) {
            if(s[i] == '-' || isdigit(s[i])) {
                bool isNeg = false;
                if(s[i] == '-') {
                    isNeg = true;
                    i += 1;
                }
                int num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i += 1;
                }
                i -= 1;
                if(isNeg) num = -num;
                st.top().add(NestedInteger(num));
            } else if(s[i] == '[') {
                st.push(NestedInteger());
            } else if(s[i] == ']') {
                if(st.size() > 1) {
                    auto cur = st.top();
                    st.pop();
                    st.top().add(cur);
                }
            }
        }
        return st.top();
    }
};