// 402. Remove K Digits [M]
// LeetCode remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> monoSt;
        for(char c : num) {
            while(!monoSt.empty() && monoSt.top() > c && k > 0) {
                k -= 1;
                monoSt.pop();
            }
            monoSt.push(c);
        }
        while(k > 0 && !monoSt.empty()) {
            k -= 1;
            monoSt.pop();
        }
        if(monoSt.empty()) return "0";
        string ans = "";
        while(!monoSt.empty()) {
            ans += monoSt.top();
            monoSt.pop();
        }
        reverse(ans.begin(), ans.end());
        int pos = ans.find_first_not_of('0');
        ans.erase(0, pos);
        if(ans.empty()) return "0";
        return ans;
    }
};