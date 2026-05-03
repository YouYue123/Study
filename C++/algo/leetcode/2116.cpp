// 2116. Check if a Parentheses String Can Be Valid [M]
// LeetCode check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> leftSt;
        stack<int> openSt;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            char lock = locked[i];
            if(lock == '1' && c == ')') {
                if(!leftSt.empty()) {
                    leftSt.pop();
                } else if(!openSt.empty()) {
                    openSt.pop();
                }else {
                    return false;
                }
            } else if(lock == '0'){
                openSt.push(i);
            } else {
                leftSt.push(i);
            }
        }
        while(!leftSt.empty() && !openSt.empty()) {
            if(leftSt.top() < openSt.top()) {
                leftSt.pop();
                openSt.pop();
            } else {
                return false;
            }
        }
        return leftSt.empty() && openSt.size() % 2 == 0;
    }
};