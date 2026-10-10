#include <bits/stdc++.h>
using namespace std;

// 1063. Number of Valid Subarrays [H]
// LeetCode number-of-valid-subarrays

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                // cout << i << " " << st.top() << endl;
                ans += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};