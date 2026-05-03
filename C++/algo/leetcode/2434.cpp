// 2434. Using a Robot to Print the Lexicographically Smallest String [M]
// LeetCode using-a-robot-to-print-the-lexicographically-smallest-string

class Solution {
public:
    string robotWithString(string s) {
        unordered_map<int, int> dict;
        for(char c : s) dict[c - 'a'] += 1;
        stack<char> st;
        string ans = "";
        char curMinChar = 'a';
        for(char c : s) {
            st.push(c);
            dict[c - 'a'] -= 1;
            for(int i = 0; i < 26; i ++) {
                if(dict[i] > 0) {
                    curMinChar = i + 'a';
                    break;
                }
            }
            // cout << curMinChar << endl;
            while(!st.empty() && st.top() <= curMinChar) {
                ans += st.top();
                st.pop();
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};