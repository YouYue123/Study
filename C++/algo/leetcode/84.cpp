// 84. Largest Rectangle in Histogram [H]
// LeetCode largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; i ++) {
            int cur_h = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > cur_h) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans = max(ans, h * (i - left - 1));
            }
            st.push(i);
        }
        return ans;
    }
};