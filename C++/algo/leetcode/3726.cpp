// 3726. Remove Zeros in Decimal Representation [E]
// LeetCode remove-zeros-in-decimal-representation

class Solution {
public:
    long long removeZeros(long long n) {
        string n_s = to_string(n);
        string ans_s = "";
        for(char c : n_s) {
            if(c != '0') ans_s += c;
        }
        return stol(ans_s);
    }
};