// 682. Baseball Game [E]
// LeetCode baseball-game

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string& op : operations) {
            if(op == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            } else if(op == "D") {
                st.push(st.top() * 2);
            } else if(op == "C") {
                st.pop();
            } else {
                st.push(stoi(op));
            }
        }
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};