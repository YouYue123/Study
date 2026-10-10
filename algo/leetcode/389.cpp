#include <bits/stdc++.h>
using namespace std;

// 389. Find the Difference [E]
// LeetCode find-the-difference

// 位运算解法
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char c : s) ans ^= c;
        for (char d : t) ans ^= d;

        // 根据异或运算规则，所有字符的异或结果就是多出来的那个字符
        return (char) ans;
    }
};
