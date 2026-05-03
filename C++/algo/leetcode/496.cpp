#include <bits/stdc++.h>
using namespace std;

// 496. Next Greater Element I [E]
// LeetCode next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),  m = nums2.size();
        stack<int> st;
        unordered_map<int, int> dict;
        for(int i = 0; i < m; i ++) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                // cout << nums2[st.top()] << " " << i << endl;
                dict[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int num : nums1) {
            if(dict.contains(num)) {
                ans.push_back(dict[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};