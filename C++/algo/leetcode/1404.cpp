// 1404. Number of Steps to Reduce a Number in Binary Representation to One [M]
// LeetCode number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    string addOne(string& s) {
        int n = s.size();
        int carry = 1;
        string nxt = "";
        for(int i = n - 1; i >= 0; i --) {
            int temp = (s[i] - '0') + carry;
            nxt += temp % 2 + '0';
            carry = temp / 2;
        }
        if(carry == 1) nxt += '1';
        reverse(nxt.begin(), nxt.end());
        return nxt;
    }
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        while(s != "1") {
            int num = s[s.size() - 1] - '0';
            if(num == 0) {
                s = s.substr(0, s.size() - 1);
                ans += 1;
            } else {
                s = addOne(s);
                // cout << "after AddOne: " << s << endl;
                s = s.substr(0, s.size() - 1);
                ans += 2;
            }
            // cout << s << endl;
        }
        
        return ans;
    }
};