#include <bits/stdc++.h>
using namespace std;

// 2216. Minimum Deletions to Make Array Beautiful [M]
// LeetCode minimum-deletions-to-make-array-beautiful

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int num : nums) {
            if(!st.empty() && st.size() % 2 == 1 && st.top() == num) {
                continue;
            } else {
                st.push(num);
            }
        }
        return st.size() % 2 == 0 ? n - st.size() : n - st.size() + 1;
    }
};