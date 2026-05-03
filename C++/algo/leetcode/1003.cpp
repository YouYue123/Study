// 1003. Check If Word Is Valid After Substitutions [M]
// LeetCode check-if-word-is-valid-after-substitutions

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == 'c') {
                if(st.size() >= 2) {
                    char prev = st.top();
                    st.pop();
                    char prev2 = st.top();
                    // cout << prev << " " << prev2 << endl;
                    if(prev == 'b' && prev2 == 'a') {
                        st.pop();
                        continue;
                    } else {
                        st.push(prev);
                    }
                }
            }
            st.push(c);
        }
        return st.empty();
    }
};