#include <bits/stdc++.h>
using namespace std;

// 1071. Greatest Common Divisor of Strings [E]
// LeetCode greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) {
            return "";
        }
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};